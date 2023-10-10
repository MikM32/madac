#include <stdint.h>
#include "linked_list.h"
#include "tokens.h"

extern enum at
{
    t_algoritmo=1,
    t_vardecl,
}arbol_tipo;

extern enum et
{
    numero,
    num_flotante,
    variable,
    val_log,
    binop,
    unop,
    func_llamada
}expr_tipo;

extern enum st
{
    asign_var=1,
    cond_si,
    bucle_mientras
}sent_tipo;

extern enum tids
{
    t_entero=20,
    t_real,
    t_logico,
    t_caracter,
    t_no_nativo
}tipos_ids;

typedef uint8_t byte;

typedef struct _Arbol Arbol;
typedef struct _Expr Expr;
typedef struct _Sent Sent;

typedef struct _Arbol
{
    uint8_t arbol_tipo;
    union
    {
        struct s_algoritmo
        {
            char* algoritmo_ident;
            lista_nodo* algoritmo_decl_var;
            lista_nodo* a_nominadas;

            Sent* cuerpo_sentencias;
        }algoritmo_data;

        struct a_nominada
        {
            char* a_nom_id;
            lista_nodo* a_nom_decl_var;

            Sent* sentencias;
        }a_nominada_data;

        struct var_decl
        {
            lista_nodo* ids;
            uint8_t vtipo;
            char* vtipo_id;
        }var_decl_data;

        //Por hacer: arreglos

        Sent* sentencia;
    }arbol_data;

}Arbol;

typedef struct _Sent
{
    uint8_t sent_tipo;
    union 
    {
        struct asgn_var_struct{ char *var;
                Expr* valor;
                
                }asign_var;

        struct proc_llamada_struct{ char* id;

        }proc_llamada;

        lista_nodo* sentencia_compuesta;
    };
}Sent;


typedef struct _Expr
{
    uint8_t expr_tipo;
    byte dato_tipo;
    uint32_t linea;
    char* text;
    union
    {
        struct opb_data{
            Expr *op1, *op2;
            uint8_t b_res_tipo;
            uint8_t b_operador;
        }op_binaria;

        struct opu_data{
            Expr *op;
            uint8_t u_res_tipo;
            uint8_t u_operador;
        }op_unaria;

        struct fnll_data{
            char* id;
            lista_nodo* args_expr;
        }func_llamada;

        int32_t num;
        float rnum;
        char* variable;
    };
}Expr;

Expr *expr_numero(Token* tok);
Expr *expr_numeroreal(Token* tok);
Expr *expr_logico(Token* tok);
Expr *expr_variable(Token* tok);
Expr *expr_unop(Token* tok,Expr* op1, uint8_t opera);
Expr *expr_binop(Token* tok,Expr* op1, uint8_t opera, Expr* op2);
