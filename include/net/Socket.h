#pragma once

namespace clp {
class Socket {
   public:
    Socket();
    explicit Socket(int fd);
    ~Socket();

    int fd() const;
    void shutdownonWrite();

   private:
    int _fd;
};

}  // namespace clp
