##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=madac
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/mike32/Documentos/C/madac/madac
ProjectPath            :=/home/mike32/Documentos/C/madac/madac/madac
IntermediateDirectory  :=../build-$(ConfigurationName)/madac
OutDir                 :=../build-$(ConfigurationName)/madac
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Mike
Date                   :=10/10/23
CodeLitePath           :=/home/mike32/.codelite
LinkerName             :=/usr/bin/g++-11
SharedObjectLinkerName :=/usr/bin/g++-11 -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-11
CC       := /usr/bin/gcc-11
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/madac/up_lexico.c$(ObjectSuffix) ../build-$(ConfigurationName)/madac/up_linked_list.c$(ObjectSuffix) ../build-$(ConfigurationName)/madac/up_hashmap.c$(ObjectSuffix) ../build-$(ConfigurationName)/madac/up_sintatico.c$(ObjectSuffix) ../build-$(ConfigurationName)/madac/up_errores.c$(ObjectSuffix) ../build-$(ConfigurationName)/madac/up_arbol_tipos.c$(ObjectSuffix) ../build-$(ConfigurationName)/madac/up_utiles.c$(ObjectSuffix) ../build-$(ConfigurationName)/madac/up_tokens.c$(ObjectSuffix) ../build-$(ConfigurationName)/madac/up_interprete.c$(ObjectSuffix) ../build-$(ConfigurationName)/madac/up_main.c$(ObjectSuffix) \
	



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/madac/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/madac"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/madac"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/madac/.d:
	@mkdir -p "../build-$(ConfigurationName)/madac"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/madac/up_lexico.c$(ObjectSuffix): ../lexico.c ../build-$(ConfigurationName)/madac/up_lexico.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/mike32/Documentos/C/madac/madac/lexico.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_lexico.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/madac/up_lexico.c$(DependSuffix): ../lexico.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/madac/up_lexico.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/madac/up_lexico.c$(DependSuffix) -MM ../lexico.c

../build-$(ConfigurationName)/madac/up_lexico.c$(PreprocessSuffix): ../lexico.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/madac/up_lexico.c$(PreprocessSuffix) ../lexico.c

../build-$(ConfigurationName)/madac/up_linked_list.c$(ObjectSuffix): ../linked_list.c ../build-$(ConfigurationName)/madac/up_linked_list.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/mike32/Documentos/C/madac/madac/linked_list.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_linked_list.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/madac/up_linked_list.c$(DependSuffix): ../linked_list.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/madac/up_linked_list.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/madac/up_linked_list.c$(DependSuffix) -MM ../linked_list.c

../build-$(ConfigurationName)/madac/up_linked_list.c$(PreprocessSuffix): ../linked_list.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/madac/up_linked_list.c$(PreprocessSuffix) ../linked_list.c

../build-$(ConfigurationName)/madac/up_hashmap.c$(ObjectSuffix): ../hashmap.c ../build-$(ConfigurationName)/madac/up_hashmap.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/mike32/Documentos/C/madac/madac/hashmap.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_hashmap.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/madac/up_hashmap.c$(DependSuffix): ../hashmap.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/madac/up_hashmap.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/madac/up_hashmap.c$(DependSuffix) -MM ../hashmap.c

../build-$(ConfigurationName)/madac/up_hashmap.c$(PreprocessSuffix): ../hashmap.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/madac/up_hashmap.c$(PreprocessSuffix) ../hashmap.c

../build-$(ConfigurationName)/madac/up_sintatico.c$(ObjectSuffix): ../sintatico.c ../build-$(ConfigurationName)/madac/up_sintatico.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/mike32/Documentos/C/madac/madac/sintatico.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_sintatico.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/madac/up_sintatico.c$(DependSuffix): ../sintatico.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/madac/up_sintatico.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/madac/up_sintatico.c$(DependSuffix) -MM ../sintatico.c

../build-$(ConfigurationName)/madac/up_sintatico.c$(PreprocessSuffix): ../sintatico.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/madac/up_sintatico.c$(PreprocessSuffix) ../sintatico.c

../build-$(ConfigurationName)/madac/up_errores.c$(ObjectSuffix): ../errores.c ../build-$(ConfigurationName)/madac/up_errores.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/mike32/Documentos/C/madac/madac/errores.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_errores.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/madac/up_errores.c$(DependSuffix): ../errores.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/madac/up_errores.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/madac/up_errores.c$(DependSuffix) -MM ../errores.c

../build-$(ConfigurationName)/madac/up_errores.c$(PreprocessSuffix): ../errores.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/madac/up_errores.c$(PreprocessSuffix) ../errores.c

../build-$(ConfigurationName)/madac/up_arbol_tipos.c$(ObjectSuffix): ../arbol_tipos.c ../build-$(ConfigurationName)/madac/up_arbol_tipos.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/mike32/Documentos/C/madac/madac/arbol_tipos.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_arbol_tipos.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/madac/up_arbol_tipos.c$(DependSuffix): ../arbol_tipos.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/madac/up_arbol_tipos.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/madac/up_arbol_tipos.c$(DependSuffix) -MM ../arbol_tipos.c

../build-$(ConfigurationName)/madac/up_arbol_tipos.c$(PreprocessSuffix): ../arbol_tipos.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/madac/up_arbol_tipos.c$(PreprocessSuffix) ../arbol_tipos.c

../build-$(ConfigurationName)/madac/up_utiles.c$(ObjectSuffix): ../utiles.c ../build-$(ConfigurationName)/madac/up_utiles.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/mike32/Documentos/C/madac/madac/utiles.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_utiles.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/madac/up_utiles.c$(DependSuffix): ../utiles.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/madac/up_utiles.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/madac/up_utiles.c$(DependSuffix) -MM ../utiles.c

../build-$(ConfigurationName)/madac/up_utiles.c$(PreprocessSuffix): ../utiles.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/madac/up_utiles.c$(PreprocessSuffix) ../utiles.c

../build-$(ConfigurationName)/madac/up_tokens.c$(ObjectSuffix): ../tokens.c ../build-$(ConfigurationName)/madac/up_tokens.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/mike32/Documentos/C/madac/madac/tokens.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_tokens.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/madac/up_tokens.c$(DependSuffix): ../tokens.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/madac/up_tokens.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/madac/up_tokens.c$(DependSuffix) -MM ../tokens.c

../build-$(ConfigurationName)/madac/up_tokens.c$(PreprocessSuffix): ../tokens.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/madac/up_tokens.c$(PreprocessSuffix) ../tokens.c

../build-$(ConfigurationName)/madac/up_interprete.c$(ObjectSuffix): ../interprete.c ../build-$(ConfigurationName)/madac/up_interprete.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/mike32/Documentos/C/madac/madac/interprete.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_interprete.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/madac/up_interprete.c$(DependSuffix): ../interprete.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/madac/up_interprete.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/madac/up_interprete.c$(DependSuffix) -MM ../interprete.c

../build-$(ConfigurationName)/madac/up_interprete.c$(PreprocessSuffix): ../interprete.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/madac/up_interprete.c$(PreprocessSuffix) ../interprete.c

../build-$(ConfigurationName)/madac/up_main.c$(ObjectSuffix): ../main.c ../build-$(ConfigurationName)/madac/up_main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/mike32/Documentos/C/madac/madac/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_main.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/madac/up_main.c$(DependSuffix): ../main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/madac/up_main.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/madac/up_main.c$(DependSuffix) -MM ../main.c

../build-$(ConfigurationName)/madac/up_main.c$(PreprocessSuffix): ../main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/madac/up_main.c$(PreprocessSuffix) ../main.c


-include ../build-$(ConfigurationName)/madac//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


