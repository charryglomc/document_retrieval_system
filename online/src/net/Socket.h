#ifndef __MY_SOCKET_H_
#define __MY_SOCKET_H_

namespace clp
{
    class Socket
    {
    public:
        Socket();
        explicit
        Socket(int fd);
        ~Socket();
        int getFd() const;
        void shutdown_write();
    private:
        int _fd;
    };
} // namespace clp

#endif