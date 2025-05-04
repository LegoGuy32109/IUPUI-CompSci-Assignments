# for assignment 3, must be outside a3 directory
server: ./a3/store/Server.class
	java a3.store.Server

./a3/store/Server.class: ./a3/store/Server.java
	javac ./a3/store/Server.java

client: ./a3/client/Client.class
	java a3.client.Client

./a3/client/Client.class: ./a3/client/Client.java
	javac ./a3/client/Client.java

./A3.jar: ./a3/store/Server.class ./a3/client/Client.class
	jar cf A3.jar a3/common/*class a3/store/*class a3/client/*class

serverRun: ./A3.jar
	java -cp A3.jar a3/store/Server

clientRun: ./A3.jar
	java -cp A3.jar a3/client/Client

all:
	javac ./a3/client/Client.java
	javac ./a3/store/Server.java

clean:
	rm ./a3/*/*.class
	rm *.jar
