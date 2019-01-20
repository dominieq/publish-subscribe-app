#ifndef SERVER_DECIPHER_H
#define SERVER_DECIPHER_H

#include <iostream>
#include <list>
#include "connection.h"
#include "publication.h"
#include "user.h"

using namespace std;

class Decipher {

public: //TODO
    static string part(string, unsigned int);
    static string pubprepare(Publication *);
    static void a_join(string, Connection *);
    static void a_join_new(string, Connection *);
    static void a_join_old(string, Connection *);
    static void a_ack_tag(string, Connection *);
    static void a_ack_pub(string, Connection *);
    static void a_err_tag(string, Connection *);
    static void a_err_pub(string, Connection *);
    static void a_sub(string, Connection *);
    static void a_send_pub(string, Connection *);
    static void a_term(string, Connection *);

    static void publishing(Publication *);
    static void publishing(User *, Connection *);
    static void publishing(Tag *, Connection *);


public:
    static void study(string, Connection *);
};


#endif //SERVER_DECIPHER_H