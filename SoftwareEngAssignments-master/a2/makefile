## take this out of a2 to run
serverRun: ./a2/store/Server.class
	java a2.store.Server

./a2/store/Server.class: ./a2/store/Server.java
	javac ./a2/store/Server.java

clientRun: ./a2/client/Client.class
	java a2.client.Client

./a2/client/Client.class: ./a2/client/Client.java
	javac ./a2/client/Client.java

all:
	javac ./a2/client/Client.java
	javac ./a2/store/Server.java

clean:
	rm ./a2/*/*.class
