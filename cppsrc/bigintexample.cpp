#include <napi.h>
#include <iostream>
#include "bigintexample.h"



uint32_t ptr[4] = {0xFF,0x00,0x00,0x00};
union u32u64_t {
    uint32_t* sig32;
    uint64_t* sig64;
};

u32u64_t gptr;

Napi::BigInt bigintexample::GetWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    
    std::cout << gptr.sig64[0] << " " << gptr.sig64[1] << std::endl;
    Napi::BigInt returnValue = Napi::BigInt::New(env, 0, 2, gptr.sig64);// bigintexample::hello());

    return returnValue;
}

void bigintexample::SetWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t temp;
    if(info.Length() > 1 || (info.Length() == 1 && !info[0].IsNumber())) {
	Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    }

    if(info.Length() == 1) {
	Napi::BigInt val = info[0].As<Napi::BigInt>();
	val.ToWords(1, 0, &temp);//gptr.sig64);
    }
}
    
    


Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    gptr.sig32 = ptr;
    exports.Set("set", Napi::Function::New(env, bigintexample::SetWrapped));
    exports.Set("get", Napi::Function::New(env, bigintexample::GetWrapped));
    return exports;
}
  

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll);
