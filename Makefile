# Compilateur et options
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -I include

# Dossiers
SRC_DIR = src
BIN_DIR = bin

# Nom de l'exécutable
TARGET = $(BIN_DIR)/DungeonBattle

# Liste automatique des fichiers sources .cpp dans src/
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Règle par défaut
all: $(TARGET)

# Règle de compilation
$(TARGET): $(SRCS)
	@mkdir -p $(BIN_DIR)
	@echo "Compilation du projet..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
	@echo "Succes ! L'executable est dans $(TARGET)"

# Règle de nettoyage
clean:
	@echo "Nettoyage..."
	rm -rf $(BIN_DIR)

# Règle pour lancer le jeu après compilation
run: all
	./$(TARGET)

.PHONY: all clean run