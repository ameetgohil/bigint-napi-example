#include <napi.h>
#include "bigintexample.h"

std::int64_t bigintexample::hello() {
    return 1234;
}

Napi::BigInt bigintexample::HelloWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::BigInt returnValue = Napi::BigInt::New(env, bigintexample::hello());

    return returnValue;
}


Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    exports.Set("hello", Napi::Function::New(env, bigintexample::HelloWrapped));
    return exports;
}
  

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll);
