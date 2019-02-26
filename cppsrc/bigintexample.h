#include <napi.h>

namespace bigintexample {
    //    std::uint64_t* set();
    Napi::BigInt GetWrapped(const Napi::CallbackInfo& info);
    void SetWrapped(const Napi::CallbackInfo& info);
    Napi::Object Init(Napi::Env env, Napi::Object exports);
}
