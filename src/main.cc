#include "nan.h"
#include "async.h"

namespace {

NAN_METHOD(SetPassword) {
  SetPasswordWorker* worker = new SetPasswordWorker(
    *Nan::Utf8String(info[0]),
    *Nan::Utf8String(info[1]),
    *Nan::Utf8String(info[2]),
    new Nan::Callback(Nan::To<v8::Function>(info[3]).ToLocalChecked()));
  Nan::AsyncQueueWorker(worker);
}

NAN_METHOD(GetPassword) {
  GetPasswordWorker* worker = new GetPasswordWorker(
    *Nan::Utf8String(info[0]),
    *Nan::Utf8String(info[1]),
    new Nan::Callback(Nan::To<v8::Function>(info[2]).ToLocalChecked()));
  Nan::AsyncQueueWorker(worker);
}

NAN_METHOD(DeletePassword) {
  DeletePasswordWorker* worker = new DeletePasswordWorker(
    *Nan::Utf8String(info[0]),
    *Nan::Utf8String(info[1]),
    new Nan::Callback(Nan::To<v8::Function>(info[2]).ToLocalChecked()));
  Nan::AsyncQueueWorker(worker);
}

NAN_METHOD(FindPassword) {
  FindPasswordWorker* worker = new FindPasswordWorker(
    *Nan::Utf8String(info[0]),
     new Nan::Callback(Nan::To<v8::Function>(info[1]).ToLocalChecked()));
  Nan::AsyncQueueWorker(worker);
}

NAN_METHOD(FindCredentials) {
  FindCredentialsWorker* worker = new FindCredentialsWorker(
    *Nan::Utf8String(info[0]),
     new Nan::Callback(Nan::To<v8::Function>(info[1]).ToLocalChecked()));
  Nan::AsyncQueueWorker(worker);
}

void Init(v8::Handle<v8::Object> exports) {
  Nan::SetMethod(exports, "getPassword", GetPassword);
  Nan::SetMethod(exports, "setPassword", SetPassword);
  Nan::SetMethod(exports, "deletePassword", DeletePassword);
  Nan::SetMethod(exports, "findPassword", FindPassword);
  Nan::SetMethod(exports, "findCredentials", FindCredentials);
}

}  // namespace

NODE_MODULE(keytar, Init)
