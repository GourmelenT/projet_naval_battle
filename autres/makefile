# Makefile du projet "Bataille navale" A PLACER à la racine de votre projet sous Eclipse

# Chaque classe du projet doit être testée séparément.
# Il y aura donc un lanceur (main) par classe à tester.

# Ce makefile doit permettre de faire :
#	- la compilation du lanceur associé à chaque classe à tester
#	- la compilation du projet final (c-à-d main.cpp)

# Déclaration de quelques variables utiles au makefile
GPP = g++ -Wall
SRC = ../src
BIN = ../bin

# La cible "deleteAll" est exécutée en tapant la commande "make deleteAll"
deleteAll :
	@# Précéder chaque commande d'une TABULATION
	@echo suppression du contenu du répertoire ../bin
	rm -f $(BIN)/*.o $(BIN)/*.bin

# Test de la classe CBateau
# Compilation du lanceur testCBateau, pour cela (l'ordre make -f ${workspace_loc}/ProjetNavalBattle/makefile compilTestCBateau
# de compilation est important en C++) :
#	- supprimer le contenu du répertoire "../bin" et
#	- d'abord compiler CBateau
#	- ensuite compiler testCBateau

# ------------------- CBateau ------------------- #

# La cible "testCBateau" est exécutée en tapant la commande "make testCBateau"
testCBateau : deleteAll compilCBateau compilTestCBateau

# La cible "compilCBateau" est exécutée en tapant la commande "make compilCBateau"
compilCBateau :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CBateau
	$(GPP) $(SRC)/CBateau.cpp -o $(BIN)/CBateau.o -c

# La cible "compilTestCBateau" est exécutée en tapant la commande "make compilTestCBateau"
compilTestCBateau :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation testCBateau
	$(GPP) $(SRC)/testCBateau.cpp $(BIN)/CBateau.o -o $(BIN)/testCBateau.bin

# ------------------- CArmada ------------------- #

# La cible "testCArmada" est exécutée en tapant la commande "make testCArmada"
testCArmada : deleteAll compilCBateau compilCArmada compilTestCArmada

# La cible "compilCArmada" est exécutée en tapant la commande "make compilCArmada"
compilCArmada :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CArmada
	$(GPP) $(SRC)/CArmada.cpp -o $(BIN)/CArmada.o -c

# La cible "compilTestCArmada" est exécutée en tapant la commande "make compilTestCArmada"
compilTestCArmada :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation testCArmada
	$(GPP) $(SRC)/testCArmada.cpp $(BIN)/CBateau.o $(BIN)/CArmada.o -o $(BIN)/testCArmada.bin

# ------------------- CGui ------------------- #

# -- CCoups -- #
compilCCoups :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CCoups
	$(GPP) $(SRC)/CCoups.cpp -o $(BIN)/CCoups.o -c

# ------------ #

# La cible "testCArmada" est exécutée en tapant la commande "make testCArmada"
testCGui : deleteAll compilCBateau compilCArmada compilCCoups compilCGui compilTestCGui

# La cible "compilCGui" est exécutée en tapant la commande "make compilCGui"
compilCGui :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CGui
	$(GPP) $(SRC)/CGui.cpp -o $(BIN)/CGui.o -c

# La cible "compilTestCGui" est exécutée en tapant la commande "make compilTestCGui"
compilTestCGui:
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation testCGui
	$(GPP) $(SRC)/testCGui.cpp $(BIN)/CBateau.o $(BIN)/CArmada.o $(BIN)/CCoups.o $(BIN)/CGui.o -o $(BIN)/testCGui.bin

# ------------------- CSocket ------------------- #

# La cible "compilCSocket" est exécutée en tapant la commande "make compilCSocket"
compilCSocket :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CSocket
	$(GPP) $(SRC)/CSocket.cpp -o $(BIN)/CSocket.o -c

# La cible "compilTestCSocket" est exécutée en tapant la commande "make compilTestCSocket"
compilTestCSocket:
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation testCSocket
	$(GPP) $(SRC)/testCSocket.cpp $(BIN)/CSocket.o -o $(BIN)/testCSocket.bin

# ------------------- CClientSocket ------------------- #

# La cible "compilCClientSocket" est exécutée en tapant la commande "make compilCClientSocket"
compilCClientSocket :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CClientSocket
	$(GPP) $(SRC)/CClientSocket.cpp -o $(BIN)/CClientSocket.o -c

# La cible "compilTestCClientSocket" est exécutée en tapant la commande "make compilTestCClientSocket"
compilTestCClientSocket:
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation testCClientSocket
	$(GPP) $(SRC)/testCClientSocket.cpp $(BIN)/CClientSocket.o -o $(BIN)/testCClientSocket.bin
	
# ------------------- CServerSocket ------------------- #

# La cible "compilCServerSocket" est exécutée en tapant la commande "make compilCServerSocket"
compilCServerSocket :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CServerSocket
	$(GPP) $(SRC)/CServerSocket.cpp -o $(BIN)/CServerSocket.o -c

# La cible "compilTestCServerSocket" est exécutée en tapant la commande "make compilTestCServerSocket"
compilTestCServerSocket:
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation testCServerSocket
	$(GPP) $(SRC)/testCServerSocket.cpp $(BIN)/CServerSocket.o -o $(BIN)/testCServerSocket.bin

# ------------------- CJoueur ------------------- #

# La cible "compilCJoueur" est exécutée en tapant la commande "make compilCJoueur"
compilCJoueur :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CJoueur
	$(GPP) $(SRC)/CJoueur.cpp -o $(BIN)/CJoueur.o -c

# La cible "compilTestCJoueur" est exécutée en tapant la commande "make compilTestCJoueur"
compilTestCJoueur:
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation testCJoueur
	$(GPP) $(SRC)/testCJoueur.cpp $(BIN)/CJoueur.o -o $(BIN)/testCJoueur.bin
	
# ------------------- CJoueurCli ------------------- #

# La cible "compilCJoueurCli" est exécutée en tapant la commande "make compilCJoueurCli"
compilCJoueurCli :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CJoueurCli
	$(GPP) $(SRC)/CJoueurCli.cpp -o $(BIN)/CJoueurCli.o -c

# La cible "compilTestCJoueurCli" est exécutée en tapant la commande "make compilTestCJoueurCli"
compilTestCJoueurCli:
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation testCJoueurCli
	$(GPP) $(SRC)/testCJoueurCli.cpp $(BIN)/CJoueurCli.o -o $(BIN)/testCJoueurCli.bin
	
# ------------------- CJoueurServ ------------------- #

# La cible "compilCJoueurServ" est exécutée en tapant la commande "make compilCJoueurServ"
compilCJoueurServ :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CJoueurServ
	$(GPP) $(SRC)/CJoueurServ.cpp -o $(BIN)/CJoueurServ.o -c

# La cible "compilTestCJoueurServ" est exécutée en tapant la commande "make compilTestCJoueurServ"
compilTestCJoueurServ:
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation testCJoueurServ
	$(GPP) $(SRC)/testCJoueurServ.cpp $(BIN)/CJoueur.o -o $(BIN)/testCJoueurServ.bin
	

# ------------------- LanceurFinal ------------------- #

# La cible "lanceurFinal" est exécutée en tapant la commande "make lanceurFinal"
lanceurFinal : deleteAll compilCBateau compilCArmada compilCCoups compilCGui compilCSocket compilCClientSocket compilCServerSocket compilCJoueur compilCJoueurCli compilCJoueurServ
	@echo Compilation lanceurFinal
	$(GPP) $(SRC)/main.cpp $(BIN)/CBateau.o $(BIN)/CArmada.o $(BIN)/CCoups.o $(BIN)/CGui.o $(BIN)/CSocket.o $(BIN)/CClientSocket.o $(BIN)/CServerSocket.o $(BIN)/CJoueur.o $(BIN)/CJoueurCli.o $(BIN)/CJoueurServ.o -o $(BIN)/main.bin


# ------------------- Lanceur du Jeu ------------------- #

# La cible "launchGame" est exécutée en tapant la commande "make launchGame"
startGame :
	@# Précéder chaque commande d'une TABULATION
	@echo Lancement main
	$(BIN)/main.bin
	
# La cible "play" est exécutée en tapant la commande "make play"
play : lanceurFinal startGame