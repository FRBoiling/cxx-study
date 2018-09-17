//
// Created by boil on 18-9-17.
//

#ifndef BOIL_CONNECTIONELEMENT_H
#define BOIL_CONNECTIONELEMENT_H

#include "TcpConnection.h"

namespace boil {
    class ConnectionElement {
    public:
        ConnectionElement(std::shared_ptr<TcpConnection> connection)
                : connection_(connection) {

        }

        ~ConnectionElement() {
            std::shared_ptr<TcpConnection> connection = connection_.lock();
            if (connection) {
                connection->onSocketClose();
            }
        }

    private:
        std::weak_ptr<boil::TcpConnection> connection_;
    };

}
#endif //BOIL_CONNECTIONELEMENT_H
