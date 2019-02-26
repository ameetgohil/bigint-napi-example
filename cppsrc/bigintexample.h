#include <napi.h>

namespace bigintexample {
    std::int64_t hello();
    Napi::BigInt HelloWrapped(const Napi::CallbackInfo& info);
    Napi::Object Init(Napi::Env env, Napi::Object exports);
}
