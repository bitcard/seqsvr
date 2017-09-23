/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "MediateService.h"
#include <thrift/lib/cpp/TApplicationException.h>
#include <folly/io/IOBuf.h>
#include <folly/io/IOBufQueue.h>
#include <thrift/lib/cpp/transport/THeader.h>
#include <thrift/lib/cpp2/server/Cpp2ConnContext.h>
#include <thrift/lib/cpp2/GeneratedCodeHelper.h>
#include <thrift/lib/cpp2/GeneratedSerializationCodeHelper.h>

namespace seqsvr {

typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRUCT,  ::seqsvr::NodeAddrInfo*>> MediateService_RegisterAllocSvr_pargs;
typedef apache::thrift::ThriftPresult<true> MediateService_RegisterAllocSvr_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRUCT,  ::seqsvr::NodeAddrInfo*>> MediateService_UnRegisterAllocSvr_pargs;
typedef apache::thrift::ThriftPresult<true> MediateService_UnRegisterAllocSvr_presult;
template <typename ProtocolIn_, typename ProtocolOut_>
void MediateServiceAsyncProcessor::_processInThread_RegisterAllocSvr(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, false, &MediateServiceAsyncProcessor::process_RegisterAllocSvr<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void MediateServiceAsyncProcessor::process_RegisterAllocSvr(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  MediateService_RegisterAllocSvr_pargs args;
  std::unique_ptr< ::seqsvr::NodeAddrInfo> uarg_node_addr(new  ::seqsvr::NodeAddrInfo());
  args.get<0>().value = uarg_node_addr.get();
  std::unique_ptr<apache::thrift::ContextStack> c(this->getContextStack(this->getServiceName(), "MediateService.RegisterAllocSvr", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), c.get());
  }
  catch (const std::exception& ex) {
    ProtocolOut_ prot;
    if (req) {
      LOG(ERROR) << ex.what() << " in function RegisterAllocSvr";
      apache::thrift::TApplicationException x(apache::thrift::TApplicationException::TApplicationExceptionType::PROTOCOL_ERROR, ex.what());
      folly::IOBufQueue queue = serializeException("RegisterAllocSvr", &prot, ctx->getProtoSeqId(), nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), ctx->getHeader()->getWriteTransforms(), ctx->getHeader()->getMinCompressBytes()));
      eb->runInEventBaseThread([queue = std::move(queue), req = std::move(req)]() mutable {
        req->sendReply(queue.move());
      }
      );
      return;
    }
    else {
      LOG(ERROR) << ex.what() << " in oneway function RegisterAllocSvr";
    }
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(c), return_RegisterAllocSvr<ProtocolIn_,ProtocolOut_>, throw_wrapped_RegisterAllocSvr<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_RegisterAllocSvr(std::move(callback), std::move(uarg_node_addr));
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue MediateServiceAsyncProcessor::return_RegisterAllocSvr(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  MediateService_RegisterAllocSvr_presult result;
  return serializeResponse("RegisterAllocSvr", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void MediateServiceAsyncProcessor::throw_wrapped_RegisterAllocSvr(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  ProtocolOut_ prot;
   {
    if (req) {
      LOG(ERROR) << ew.what().toStdString() << " in function RegisterAllocSvr";
      apache::thrift::TApplicationException x(ew.what().toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("RegisterAllocSvr", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << ew.what().toStdString() << " in oneway function RegisterAllocSvr";
    }
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void MediateServiceAsyncProcessor::_processInThread_UnRegisterAllocSvr(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, false, &MediateServiceAsyncProcessor::process_UnRegisterAllocSvr<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void MediateServiceAsyncProcessor::process_UnRegisterAllocSvr(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  MediateService_UnRegisterAllocSvr_pargs args;
  std::unique_ptr< ::seqsvr::NodeAddrInfo> uarg_node_addr(new  ::seqsvr::NodeAddrInfo());
  args.get<0>().value = uarg_node_addr.get();
  std::unique_ptr<apache::thrift::ContextStack> c(this->getContextStack(this->getServiceName(), "MediateService.UnRegisterAllocSvr", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), c.get());
  }
  catch (const std::exception& ex) {
    ProtocolOut_ prot;
    if (req) {
      LOG(ERROR) << ex.what() << " in function UnRegisterAllocSvr";
      apache::thrift::TApplicationException x(apache::thrift::TApplicationException::TApplicationExceptionType::PROTOCOL_ERROR, ex.what());
      folly::IOBufQueue queue = serializeException("UnRegisterAllocSvr", &prot, ctx->getProtoSeqId(), nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), ctx->getHeader()->getWriteTransforms(), ctx->getHeader()->getMinCompressBytes()));
      eb->runInEventBaseThread([queue = std::move(queue), req = std::move(req)]() mutable {
        req->sendReply(queue.move());
      }
      );
      return;
    }
    else {
      LOG(ERROR) << ex.what() << " in oneway function UnRegisterAllocSvr";
    }
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(c), return_UnRegisterAllocSvr<ProtocolIn_,ProtocolOut_>, throw_wrapped_UnRegisterAllocSvr<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_UnRegisterAllocSvr(std::move(callback), std::move(uarg_node_addr));
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue MediateServiceAsyncProcessor::return_UnRegisterAllocSvr(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  MediateService_UnRegisterAllocSvr_presult result;
  return serializeResponse("UnRegisterAllocSvr", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void MediateServiceAsyncProcessor::throw_wrapped_UnRegisterAllocSvr(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  ProtocolOut_ prot;
   {
    if (req) {
      LOG(ERROR) << ew.what().toStdString() << " in function UnRegisterAllocSvr";
      apache::thrift::TApplicationException x(ew.what().toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("UnRegisterAllocSvr", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << ew.what().toStdString() << " in oneway function UnRegisterAllocSvr";
    }
  }
}

template <typename Protocol_>
void MediateServiceAsyncClient::RegisterAllocSvrT(Protocol_* prot, bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::seqsvr::NodeAddrInfo& node_addr) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(getChannel()->getProtocolId());
  header->setHeaders(rpcOptions.releaseWriteHeaders());
  connectionContext_->setRequestHeader(header.get());
  std::unique_ptr<apache::thrift::ContextStack> ctx = this->getContextStack(this->getServiceName(), "MediateService.RegisterAllocSvr", connectionContext_.get());
  MediateService_RegisterAllocSvr_pargs args;
  args.get<0>().value = const_cast< ::seqsvr::NodeAddrInfo*>(&node_addr);
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  apache::thrift::clientSendT<Protocol_>(prot, rpcOptions, std::move(callback), std::move(ctx), header, channel_.get(), "RegisterAllocSvr", writer, sizer, false, useSync);
  connectionContext_->setRequestHeader(nullptr);
}

template <typename Protocol_>
folly::exception_wrapper MediateServiceAsyncClient::recv_wrapped_RegisterAllocSvrT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  prot->setInput(state.buf());
  auto guard = folly::makeGuard([&] {prot->setInput(nullptr);});
  apache::thrift::ContextStack* ctx = state.ctx();
  std::string _fname;
  int32_t protoSeqId = 0;
  apache::thrift::MessageType mtype;
  ctx->preRead();
  folly::exception_wrapper interior_ew;
  auto caught_ew = folly::try_and_catch<std::exception, apache::thrift::TException, apache::thrift::protocol::TProtocolException>([&]() {
    prot->readMessageBegin(_fname, mtype, protoSeqId);
    if (mtype == apache::thrift::T_EXCEPTION) {
      apache::thrift::TApplicationException x;
      x.read(prot);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(x);
      return; // from try_and_catch
    }
    if (mtype != apache::thrift::T_REPLY) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::INVALID_MESSAGE_TYPE);
      return; // from try_and_catch
    }
    if (_fname.compare("RegisterAllocSvr") != 0) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::WRONG_METHOD_NAME);
      return; // from try_and_catch
    }
    ::apache::thrift::SerializedMessage smsg;
    smsg.protocolType = prot->protocolType();
    smsg.buffer = state.buf();
    ctx->onReadData(smsg);
    MediateService_RegisterAllocSvr_presult result;
    result.read(prot);
    prot->readMessageEnd();
    ctx->postRead(state.header(), state.buf()->length());
  }
  );
  auto ew = interior_ew ? std::move(interior_ew) : std::move(caught_ew);
  if (ew) {
    ctx->handlerErrorWrapped(ew);
  }
  return ew;
}

template <typename Protocol_>
void MediateServiceAsyncClient::recv_RegisterAllocSvrT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_RegisterAllocSvrT(prot, state);
  if (ew) {
    ew.throw_exception();
  }
}

template <typename Protocol_>
void MediateServiceAsyncClient::UnRegisterAllocSvrT(Protocol_* prot, bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::seqsvr::NodeAddrInfo& node_addr) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(getChannel()->getProtocolId());
  header->setHeaders(rpcOptions.releaseWriteHeaders());
  connectionContext_->setRequestHeader(header.get());
  std::unique_ptr<apache::thrift::ContextStack> ctx = this->getContextStack(this->getServiceName(), "MediateService.UnRegisterAllocSvr", connectionContext_.get());
  MediateService_UnRegisterAllocSvr_pargs args;
  args.get<0>().value = const_cast< ::seqsvr::NodeAddrInfo*>(&node_addr);
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  apache::thrift::clientSendT<Protocol_>(prot, rpcOptions, std::move(callback), std::move(ctx), header, channel_.get(), "UnRegisterAllocSvr", writer, sizer, false, useSync);
  connectionContext_->setRequestHeader(nullptr);
}

template <typename Protocol_>
folly::exception_wrapper MediateServiceAsyncClient::recv_wrapped_UnRegisterAllocSvrT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  prot->setInput(state.buf());
  auto guard = folly::makeGuard([&] {prot->setInput(nullptr);});
  apache::thrift::ContextStack* ctx = state.ctx();
  std::string _fname;
  int32_t protoSeqId = 0;
  apache::thrift::MessageType mtype;
  ctx->preRead();
  folly::exception_wrapper interior_ew;
  auto caught_ew = folly::try_and_catch<std::exception, apache::thrift::TException, apache::thrift::protocol::TProtocolException>([&]() {
    prot->readMessageBegin(_fname, mtype, protoSeqId);
    if (mtype == apache::thrift::T_EXCEPTION) {
      apache::thrift::TApplicationException x;
      x.read(prot);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(x);
      return; // from try_and_catch
    }
    if (mtype != apache::thrift::T_REPLY) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::INVALID_MESSAGE_TYPE);
      return; // from try_and_catch
    }
    if (_fname.compare("UnRegisterAllocSvr") != 0) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::WRONG_METHOD_NAME);
      return; // from try_and_catch
    }
    ::apache::thrift::SerializedMessage smsg;
    smsg.protocolType = prot->protocolType();
    smsg.buffer = state.buf();
    ctx->onReadData(smsg);
    MediateService_UnRegisterAllocSvr_presult result;
    result.read(prot);
    prot->readMessageEnd();
    ctx->postRead(state.header(), state.buf()->length());
  }
  );
  auto ew = interior_ew ? std::move(interior_ew) : std::move(caught_ew);
  if (ew) {
    ctx->handlerErrorWrapped(ew);
  }
  return ew;
}

template <typename Protocol_>
void MediateServiceAsyncClient::recv_UnRegisterAllocSvrT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_UnRegisterAllocSvrT(prot, state);
  if (ew) {
    ew.throw_exception();
  }
}

} // seqsvr
namespace apache { namespace thrift {

}} // apache::thrift
