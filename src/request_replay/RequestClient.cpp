#include <zmq.hpp>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
    //  Prepare our context and socket
    
    if (argc == 2)
    {
        zmq::context_t context(1);
        zmq::socket_t socket(context, ZMQ_REQ);
        string content(argv[1]);
        cout << content << endl;
        socket.connect("tcp://192.168.1.204:8088");

        zmq::message_t request(content.size());
        memcpy(request.data(), content.c_str(), content.size());
        socket.send(request);

        //  Get the reply.
        zmq::message_t reply;
        socket.recv(&reply);
    }

    return 0;
}