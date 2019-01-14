#include "connection.h"
#include <unistd.h>
#include <sys/socket.h>

list<Connection *> Connection::connectionlist;

Connection::Connection(int server_socket_descriptor) {
    s_accept(server_socket_descriptor);
    connectionlist.push_back(this);
    cout << "OK: Połączono klienta." << endl;
}

Connection::~Connection() {
    cout << "OK: Zamknięcie połączenia csd: " << connection_socket_descriptor << endl;
    close(connection_socket_descriptor);
}

void Connection::s_accept(int server_socket_descriptor) {
    cout << "OK: Serwer czeka na klienta." << endl;
    connection_socket_descriptor = accept(server_socket_descriptor, NULL, NULL);
    if (connection_socket_descriptor < 0) {
        cout << stderr << ": Błąd przy próbie utworzenia gniazda dla połączenia." << endl;
        exit(2);
    }
}

int Connection::s_get_connection_socket_descriptor() {
    return connection_socket_descriptor;
}

void Connection::s_read() {
    active = true;
    while (active) {
        if((dlugosc = read(connection_socket_descriptor, buffer, BUF_SIZE)) > 0) {
            buffer[dlugosc] = '\0';
            cout << buffer << endl;
            //TODO analiza
        } else {
            cout << "!!: Klient zerwał połączenie. csd: " << this->s_get_connection_socket_descriptor() << endl;
            active = false;
        }

    }
    delete this;
}

void Connection::s_write(string tresc) {
    write(connection_socket_descriptor, tresc.c_str(), tresc.size());
}

list<Connection *> Connection::get_connectionlist() {
    return connectionlist;
}