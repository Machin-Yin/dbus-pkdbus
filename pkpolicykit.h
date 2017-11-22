#ifndef PKPOLICYKIT_H
#define PKPOLICYKIT_H

#include <polkit-qt5-1/PolkitQt1/Authority>

using namespace PolkitQt1;

class PkPolicyKit {
public:
    inline static PkPolicyKit* instance(){
        static PkPolicyKit instance;
        return &instance;
    }

    bool checkAuthorization(const QString& actionId, qint64 applicationPid);

private:
    PkPolicyKit();
    ~PkPolicyKit();

    Q_DISABLE_COPY(PkPolicyKit)

};

#endif // PKPOLICYKIT_H
