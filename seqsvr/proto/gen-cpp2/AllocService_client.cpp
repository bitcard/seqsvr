/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "AllocService.h"

#include "AllocService.tcc"

#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>
#include <thrift/lib/cpp2/protocol/SimpleJSONProtocol.h>
namespace seqsvr {

const char* AllocServiceAsyncClient::getServiceName() {
  return "AllocService";
}

void AllocServiceAsyncClient::FetchNextSequence(std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t id, int32_t version) {
  ::apache::thrift::RpcOptions rpcOptions;
  FetchNextSequenceImpl(false, rpcOptions, std::move(callback), id, version);
}

void AllocServiceAsyncClient::FetchNextSequence(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t id, int32_t version) {
  FetchNextSequenceImpl(false, rpcOptions, std::move(callback), id, version);
}

void AllocServiceAsyncClient::FetchNextSequenceImpl(bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t id, int32_t version) {
  switch(getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      FetchNextSequenceT(&writer, useSync, rpcOptions, std::move(callback), id, version);
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      FetchNextSequenceT(&writer, useSync, rpcOptions, std::move(callback), id, version);
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

void AllocServiceAsyncClient::sync_FetchNextSequence( ::seqsvr::Sequence& _return, int32_t id, int32_t version) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_FetchNextSequence(rpcOptions, _return, id, version);
}

void AllocServiceAsyncClient::sync_FetchNextSequence(apache::thrift::RpcOptions& rpcOptions,  ::seqsvr::Sequence& _return, int32_t id, int32_t version) {
  apache::thrift::ClientReceiveState _returnState;
  auto callback = std::make_unique<apache::thrift::ClientSyncCallback>(&_returnState, false);
  FetchNextSequenceImpl(true, rpcOptions, std::move(callback), id, version);
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(_returnState.exception());
    _returnState.exception().throw_exception();
  }
  recv_FetchNextSequence(_return, _returnState);
}

folly::Future< ::seqsvr::Sequence> AllocServiceAsyncClient::future_FetchNextSequence(int32_t id, int32_t version) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_FetchNextSequence(rpcOptions, id, version);
}

folly::Future< ::seqsvr::Sequence> AllocServiceAsyncClient::future_FetchNextSequence(apache::thrift::RpcOptions& rpcOptions, int32_t id, int32_t version) {
  folly::Promise< ::seqsvr::Sequence> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback< ::seqsvr::Sequence>>(std::move(_promise), recv_wrapped_FetchNextSequence, channel_);
  FetchNextSequence(rpcOptions, std::move(callback), id, version);
  return _future;
}

folly::Future<std::pair< ::seqsvr::Sequence, std::unique_ptr<apache::thrift::transport::THeader>>> AllocServiceAsyncClient::header_future_FetchNextSequence(apache::thrift::RpcOptions& rpcOptions, int32_t id, int32_t version) {
  folly::Promise<std::pair< ::seqsvr::Sequence, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback< ::seqsvr::Sequence>>(std::move(_promise), recv_wrapped_FetchNextSequence, channel_);
  FetchNextSequence(rpcOptions, std::move(callback), id, version);
  return _future;
}

void AllocServiceAsyncClient::FetchNextSequence(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, int32_t id, int32_t version) {
  FetchNextSequence(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), id, version);
}

folly::exception_wrapper AllocServiceAsyncClient::recv_wrapped_FetchNextSequence( ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }
  switch(state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return recv_wrapped_FetchNextSequenceT(&reader, _return, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return recv_wrapped_FetchNextSequenceT(&reader, _return, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void AllocServiceAsyncClient::recv_FetchNextSequence( ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_FetchNextSequence(_return, state);
  if (ew) {
    ew.throw_exception();
  }
}

void AllocServiceAsyncClient::recv_instance_FetchNextSequence( ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_FetchNextSequence(_return, state);
}

folly::exception_wrapper AllocServiceAsyncClient::recv_instance_wrapped_FetchNextSequence( ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_FetchNextSequence(_return, state);
}

void AllocServiceAsyncClient::GetCurrentSequence(std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t id, int32_t version) {
  ::apache::thrift::RpcOptions rpcOptions;
  GetCurrentSequenceImpl(false, rpcOptions, std::move(callback), id, version);
}

void AllocServiceAsyncClient::GetCurrentSequence(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t id, int32_t version) {
  GetCurrentSequenceImpl(false, rpcOptions, std::move(callback), id, version);
}

void AllocServiceAsyncClient::GetCurrentSequenceImpl(bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t id, int32_t version) {
  switch(getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      GetCurrentSequenceT(&writer, useSync, rpcOptions, std::move(callback), id, version);
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      GetCurrentSequenceT(&writer, useSync, rpcOptions, std::move(callback), id, version);
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

void AllocServiceAsyncClient::sync_GetCurrentSequence( ::seqsvr::Sequence& _return, int32_t id, int32_t version) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_GetCurrentSequence(rpcOptions, _return, id, version);
}

void AllocServiceAsyncClient::sync_GetCurrentSequence(apache::thrift::RpcOptions& rpcOptions,  ::seqsvr::Sequence& _return, int32_t id, int32_t version) {
  apache::thrift::ClientReceiveState _returnState;
  auto callback = std::make_unique<apache::thrift::ClientSyncCallback>(&_returnState, false);
  GetCurrentSequenceImpl(true, rpcOptions, std::move(callback), id, version);
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(_returnState.exception());
    _returnState.exception().throw_exception();
  }
  recv_GetCurrentSequence(_return, _returnState);
}

folly::Future< ::seqsvr::Sequence> AllocServiceAsyncClient::future_GetCurrentSequence(int32_t id, int32_t version) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_GetCurrentSequence(rpcOptions, id, version);
}

folly::Future< ::seqsvr::Sequence> AllocServiceAsyncClient::future_GetCurrentSequence(apache::thrift::RpcOptions& rpcOptions, int32_t id, int32_t version) {
  folly::Promise< ::seqsvr::Sequence> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback< ::seqsvr::Sequence>>(std::move(_promise), recv_wrapped_GetCurrentSequence, channel_);
  GetCurrentSequence(rpcOptions, std::move(callback), id, version);
  return _future;
}

folly::Future<std::pair< ::seqsvr::Sequence, std::unique_ptr<apache::thrift::transport::THeader>>> AllocServiceAsyncClient::header_future_GetCurrentSequence(apache::thrift::RpcOptions& rpcOptions, int32_t id, int32_t version) {
  folly::Promise<std::pair< ::seqsvr::Sequence, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback< ::seqsvr::Sequence>>(std::move(_promise), recv_wrapped_GetCurrentSequence, channel_);
  GetCurrentSequence(rpcOptions, std::move(callback), id, version);
  return _future;
}

void AllocServiceAsyncClient::GetCurrentSequence(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, int32_t id, int32_t version) {
  GetCurrentSequence(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), id, version);
}

folly::exception_wrapper AllocServiceAsyncClient::recv_wrapped_GetCurrentSequence( ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }
  switch(state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return recv_wrapped_GetCurrentSequenceT(&reader, _return, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return recv_wrapped_GetCurrentSequenceT(&reader, _return, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void AllocServiceAsyncClient::recv_GetCurrentSequence( ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_GetCurrentSequence(_return, state);
  if (ew) {
    ew.throw_exception();
  }
}

void AllocServiceAsyncClient::recv_instance_GetCurrentSequence( ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_GetCurrentSequence(_return, state);
}

folly::exception_wrapper AllocServiceAsyncClient::recv_instance_wrapped_GetCurrentSequence( ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_GetCurrentSequence(_return, state);
}

} // seqsvr
namespace apache { namespace thrift {

}} // apache::thrift
