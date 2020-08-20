#include <zmq.hpp>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main (int argc,char ** argv)
{
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);

    std::cout << "Connecting to hello world server…" << std::endl;
    
    cout<<argc<<endl;
    if(argc == 2){
        string content(argv[1]);
        cout<<content<<endl;
        socket.connect("tcp://localhost:8088");

    zmq::message_t request(content.size());
    memcpy(request.data(), content.c_str(), content.size());
    // std::cout << "Sending Hello " << request_nbr << "…" << std::endl;
    socket.send(request);

    //  Get the reply.
    zmq::message_t reply;
    socket.recv(&reply);
    }
    

    return 0;
}