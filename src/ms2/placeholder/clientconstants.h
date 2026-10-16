// Heap-only Constants views. Object ctor1402b72d0, float getter1402bac70,
// Client ctor1402b77c0 (last Value<CString> at ea38, size60), RTTI singleton offsetae68.
#pragma once
#include <string>
#include "ms2/commonfiles/os.h"
#include "ms2/ms2layout.h"
namespace Common {
class Constants {
public:
    virtual void vfunc_0();
    virtual ~Constants();
    struct Object {
        virtual ~Object();
        virtual void vfunc_1();
        bool initialized, flag9, flagA, flagB;
        unsigned unknownC;
        std::string name, description;
    };
    template<class T> struct Value : Object { T value; T FUN_1402bac70(); };
    unsigned __int64 unknown8[0x1028 / 8];
    Value<float> cubeQueryDistance;
    unsigned __int64 unknown1088[0x9de0 / 8];
};
}
MS2_CHECK_SIZE(Common::Constants::Object,0x50);
MS2_CHECK_SIZE(Common::Constants::Value<float>,0x58);
MS2_CHECK_SIZE(Common::Constants,0xae68);
MS2_CHECK_OFFSET(Common::Constants,cubeQueryDistance,0x1030);
namespace Client {
class Constants : public Common::Constants, public TSingleton<Constants> {
public:
    virtual void vfunc_0();
    virtual ~Constants();
    unsigned __int64 unknownAe70[0x3c28 / 8];
};
}
MS2_CHECK_SIZE(Client::Constants,0xea98);
