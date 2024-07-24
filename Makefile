# Definir o compilador e as flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./src/main/cli -I./src/main/entities -O2 -lpqxx -lpq

# Diretórios
BUILDDIR = build
SRCDIR = src/main
ENTITIDIR = $(SRCDIR)/entities
REPOSITORYDIR = $(SRCDIR)/repository
SERVICEDIR = $(SRCDIR)/service
DBCONFIGDIR = $(SRCDIR)/infra/db
CLISRC = $(SRCDIR)/cli

# Arquivos de fonte e de objetos
SOURCES = $(wildcard $(ENTITIDIR)/*.cpp) $(wildcard $(CLISRC)/*.cpp) $(wildcard $(DBCONFIGDIR)/*.cpp)  $(wildcard $(REPOSITORYDIR)/*.cpp)  $(wildcard $(SERVICEDIR)/*.cpp) $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Nome do executável
TARGET = $(BUILDDIR)/beTI.bin

# Criar o diretório build se não existir
$(shell mkdir -p $(BUILDDIR))

# Regra padrão
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Regra para compilar arquivos .cpp em arquivos .o
$(BUILDDIR)/%.o: $(SOURCESDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos de objeto
clean:
	rm -f $(OBJECTS)

