#include <beast/websocket.hpp>
#include <beast/buffers_debug.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <string>

using namespace boost;
int main()
{
    // Normal boost::asio setup
    std::string const host = "echo.websocket.org";
    boost::asio::io_service ios;
    boost::asio::ip::tcp::resolver r(ios);
    boost::asio::ip::tcp::socket sock(ios);
    boost::asio::connect(sock,
        r.resolve(boost::asio::ip::tcp::resolver::query{host, "80"}));

    using namespace beast::websocket;

    // WebSocket connect and send message using beast
    stream<boost::asio::ip::tcp::socket&> ws(sock);
    ws.handshake(host, "/");
    ws.write(boost::asio::buffer("Hello, world!"));

    // Receive WebSocket message, print and close using beast
    beast::streambuf sb;
    opcode op;
    ws.read(op, sb);
    ws.close(close_code::normal);
    std::cout <<
        beast::debug::buffers_to_string(sb.data()) << "\n";
}