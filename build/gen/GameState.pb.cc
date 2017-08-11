// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: GameState.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "GameState.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
class PositionStateDefaultTypeInternal : public ::google::protobuf::internal::ExplicitlyConstructed<PositionState> {
} _PositionState_default_instance_;
class EntityStateDefaultTypeInternal : public ::google::protobuf::internal::ExplicitlyConstructed<EntityState> {
} _EntityState_default_instance_;
class GameStateDefaultTypeInternal : public ::google::protobuf::internal::ExplicitlyConstructed<GameState> {
} _GameState_default_instance_;

namespace protobuf_GameState_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[3];

}  // namespace

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTableField
    const TableStruct::entries[] = {
  {0, 0, 0, ::google::protobuf::internal::kInvalidMask, 0, 0},
};

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::AuxillaryParseTableField
    const TableStruct::aux[] = {
  ::google::protobuf::internal::AuxillaryParseTableField(),
};
PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTable const
    TableStruct::schema[] = {
  { NULL, NULL, 0, -1, -1, false },
  { NULL, NULL, 0, -1, -1, false },
  { NULL, NULL, 0, -1, -1, false },
};

const ::google::protobuf::uint32 TableStruct::offsets[] = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PositionState, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PositionState, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PositionState, x_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PositionState, y_),
  0,
  1,
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EntityState, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EntityState, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EntityState, id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EntityState, position_),
  1,
  0,
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameState, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameState, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameState, entities_),
  ~0u,
};

static const ::google::protobuf::internal::MigrationSchema schemas[] = {
  { 0, 7, sizeof(PositionState)},
  { 9, 16, sizeof(EntityState)},
  { 18, 24, sizeof(GameState)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_PositionState_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&_EntityState_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&_GameState_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "GameState.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 3);
}

}  // namespace

void TableStruct::Shutdown() {
  _PositionState_default_instance_.Shutdown();
  delete file_level_metadata[0].reflection;
  _EntityState_default_instance_.Shutdown();
  delete file_level_metadata[1].reflection;
  _GameState_default_instance_.Shutdown();
  delete file_level_metadata[2].reflection;
}

void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  _PositionState_default_instance_.DefaultConstruct();
  _EntityState_default_instance_.DefaultConstruct();
  _GameState_default_instance_.DefaultConstruct();
  _EntityState_default_instance_.get_mutable()->position_ = const_cast< ::PositionState*>(
      ::PositionState::internal_default_instance());
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] = {
      "\n\017GameState.proto\"%\n\rPositionState\022\t\n\001x\030"
      "\001 \001(\002\022\t\n\001y\030\002 \001(\002\";\n\013EntityState\022\n\n\002id\030\001 "
      "\002(\005\022 \n\010position\030\002 \001(\0132\016.PositionState\"+\n"
      "\tGameState\022\036\n\010entities\030\001 \003(\0132\014.EntitySta"
      "te"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 162);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "GameState.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&TableStruct::Shutdown);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;

}  // namespace protobuf_GameState_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int PositionState::kXFieldNumber;
const int PositionState::kYFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

PositionState::PositionState()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_GameState_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:PositionState)
}
PositionState::PositionState(const PositionState& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&x_, &from.x_,
    reinterpret_cast<char*>(&y_) -
    reinterpret_cast<char*>(&x_) + sizeof(y_));
  // @@protoc_insertion_point(copy_constructor:PositionState)
}

void PositionState::SharedCtor() {
  _cached_size_ = 0;
  ::memset(&x_, 0, reinterpret_cast<char*>(&y_) -
    reinterpret_cast<char*>(&x_) + sizeof(y_));
}

PositionState::~PositionState() {
  // @@protoc_insertion_point(destructor:PositionState)
  SharedDtor();
}

void PositionState::SharedDtor() {
}

void PositionState::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PositionState::descriptor() {
  protobuf_GameState_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_GameState_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const PositionState& PositionState::default_instance() {
  protobuf_GameState_2eproto::InitDefaults();
  return *internal_default_instance();
}

PositionState* PositionState::New(::google::protobuf::Arena* arena) const {
  PositionState* n = new PositionState;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void PositionState::Clear() {
// @@protoc_insertion_point(message_clear_start:PositionState)
  if (_has_bits_[0 / 32] & 3u) {
    ::memset(&x_, 0, reinterpret_cast<char*>(&y_) -
      reinterpret_cast<char*>(&x_) + sizeof(y_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool PositionState::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:PositionState)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional float x = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(13u)) {
          set_has_x();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &x_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional float y = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(21u)) {
          set_has_y();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &y_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:PositionState)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:PositionState)
  return false;
#undef DO_
}

void PositionState::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:PositionState)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional float x = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(1, this->x(), output);
  }

  // optional float y = 2;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(2, this->y(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:PositionState)
}

::google::protobuf::uint8* PositionState::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:PositionState)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional float x = 1;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(1, this->x(), target);
  }

  // optional float y = 2;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(2, this->y(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:PositionState)
  return target;
}

size_t PositionState::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:PositionState)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  if (_has_bits_[0 / 32] & 3u) {
    // optional float x = 1;
    if (has_x()) {
      total_size += 1 + 4;
    }

    // optional float y = 2;
    if (has_y()) {
      total_size += 1 + 4;
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PositionState::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:PositionState)
  GOOGLE_DCHECK_NE(&from, this);
  const PositionState* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const PositionState>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:PositionState)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:PositionState)
    MergeFrom(*source);
  }
}

void PositionState::MergeFrom(const PositionState& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:PositionState)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 3u) {
    if (cached_has_bits & 0x00000001u) {
      x_ = from.x_;
    }
    if (cached_has_bits & 0x00000002u) {
      y_ = from.y_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void PositionState::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:PositionState)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PositionState::CopyFrom(const PositionState& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:PositionState)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PositionState::IsInitialized() const {
  return true;
}

void PositionState::Swap(PositionState* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PositionState::InternalSwap(PositionState* other) {
  std::swap(x_, other->x_);
  std::swap(y_, other->y_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata PositionState::GetMetadata() const {
  protobuf_GameState_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_GameState_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// PositionState

// optional float x = 1;
bool PositionState::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void PositionState::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
void PositionState::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
void PositionState::clear_x() {
  x_ = 0;
  clear_has_x();
}
float PositionState::x() const {
  // @@protoc_insertion_point(field_get:PositionState.x)
  return x_;
}
void PositionState::set_x(float value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:PositionState.x)
}

// optional float y = 2;
bool PositionState::has_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
void PositionState::set_has_y() {
  _has_bits_[0] |= 0x00000002u;
}
void PositionState::clear_has_y() {
  _has_bits_[0] &= ~0x00000002u;
}
void PositionState::clear_y() {
  y_ = 0;
  clear_has_y();
}
float PositionState::y() const {
  // @@protoc_insertion_point(field_get:PositionState.y)
  return y_;
}
void PositionState::set_y(float value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:PositionState.y)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int EntityState::kIdFieldNumber;
const int EntityState::kPositionFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

EntityState::EntityState()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_GameState_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:EntityState)
}
EntityState::EntityState(const EntityState& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.has_position()) {
    position_ = new ::PositionState(*from.position_);
  } else {
    position_ = NULL;
  }
  id_ = from.id_;
  // @@protoc_insertion_point(copy_constructor:EntityState)
}

void EntityState::SharedCtor() {
  _cached_size_ = 0;
  ::memset(&position_, 0, reinterpret_cast<char*>(&id_) -
    reinterpret_cast<char*>(&position_) + sizeof(id_));
}

EntityState::~EntityState() {
  // @@protoc_insertion_point(destructor:EntityState)
  SharedDtor();
}

void EntityState::SharedDtor() {
  if (this != internal_default_instance()) {
    delete position_;
  }
}

void EntityState::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* EntityState::descriptor() {
  protobuf_GameState_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_GameState_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const EntityState& EntityState::default_instance() {
  protobuf_GameState_2eproto::InitDefaults();
  return *internal_default_instance();
}

EntityState* EntityState::New(::google::protobuf::Arena* arena) const {
  EntityState* n = new EntityState;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void EntityState::Clear() {
// @@protoc_insertion_point(message_clear_start:EntityState)
  if (has_position()) {
    GOOGLE_DCHECK(position_ != NULL);
    position_->::PositionState::Clear();
  }
  id_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool EntityState::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:EntityState)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 id = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u)) {
          set_has_id();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .PositionState position = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_position()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:EntityState)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:EntityState)
  return false;
#undef DO_
}

void EntityState::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:EntityState)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 id = 1;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // optional .PositionState position = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, *this->position_, output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:EntityState)
}

::google::protobuf::uint8* EntityState::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:EntityState)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 id = 1;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // optional .PositionState position = 2;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        2, *this->position_, deterministic, target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:EntityState)
  return target;
}

size_t EntityState::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:EntityState)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  // required int32 id = 1;
  if (has_id()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->id());
  }
  // optional .PositionState position = 2;
  if (has_position()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->position_);
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void EntityState::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:EntityState)
  GOOGLE_DCHECK_NE(&from, this);
  const EntityState* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const EntityState>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:EntityState)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:EntityState)
    MergeFrom(*source);
  }
}

void EntityState::MergeFrom(const EntityState& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:EntityState)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 3u) {
    if (cached_has_bits & 0x00000001u) {
      mutable_position()->::PositionState::MergeFrom(from.position());
    }
    if (cached_has_bits & 0x00000002u) {
      id_ = from.id_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void EntityState::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:EntityState)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void EntityState::CopyFrom(const EntityState& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:EntityState)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EntityState::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;
  return true;
}

void EntityState::Swap(EntityState* other) {
  if (other == this) return;
  InternalSwap(other);
}
void EntityState::InternalSwap(EntityState* other) {
  std::swap(position_, other->position_);
  std::swap(id_, other->id_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata EntityState::GetMetadata() const {
  protobuf_GameState_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_GameState_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// EntityState

// required int32 id = 1;
bool EntityState::has_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
void EntityState::set_has_id() {
  _has_bits_[0] |= 0x00000002u;
}
void EntityState::clear_has_id() {
  _has_bits_[0] &= ~0x00000002u;
}
void EntityState::clear_id() {
  id_ = 0;
  clear_has_id();
}
::google::protobuf::int32 EntityState::id() const {
  // @@protoc_insertion_point(field_get:EntityState.id)
  return id_;
}
void EntityState::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:EntityState.id)
}

// optional .PositionState position = 2;
bool EntityState::has_position() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void EntityState::set_has_position() {
  _has_bits_[0] |= 0x00000001u;
}
void EntityState::clear_has_position() {
  _has_bits_[0] &= ~0x00000001u;
}
void EntityState::clear_position() {
  if (position_ != NULL) position_->::PositionState::Clear();
  clear_has_position();
}
const ::PositionState& EntityState::position() const {
  // @@protoc_insertion_point(field_get:EntityState.position)
  return position_ != NULL ? *position_
                         : *::PositionState::internal_default_instance();
}
::PositionState* EntityState::mutable_position() {
  set_has_position();
  if (position_ == NULL) {
    position_ = new ::PositionState;
  }
  // @@protoc_insertion_point(field_mutable:EntityState.position)
  return position_;
}
::PositionState* EntityState::release_position() {
  // @@protoc_insertion_point(field_release:EntityState.position)
  clear_has_position();
  ::PositionState* temp = position_;
  position_ = NULL;
  return temp;
}
void EntityState::set_allocated_position(::PositionState* position) {
  delete position_;
  position_ = position;
  if (position) {
    set_has_position();
  } else {
    clear_has_position();
  }
  // @@protoc_insertion_point(field_set_allocated:EntityState.position)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int GameState::kEntitiesFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

GameState::GameState()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_GameState_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:GameState)
}
GameState::GameState(const GameState& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0),
      entities_(from.entities_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:GameState)
}

void GameState::SharedCtor() {
  _cached_size_ = 0;
}

GameState::~GameState() {
  // @@protoc_insertion_point(destructor:GameState)
  SharedDtor();
}

void GameState::SharedDtor() {
}

void GameState::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameState::descriptor() {
  protobuf_GameState_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_GameState_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const GameState& GameState::default_instance() {
  protobuf_GameState_2eproto::InitDefaults();
  return *internal_default_instance();
}

GameState* GameState::New(::google::protobuf::Arena* arena) const {
  GameState* n = new GameState;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void GameState::Clear() {
// @@protoc_insertion_point(message_clear_start:GameState)
  entities_.Clear();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool GameState::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:GameState)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .EntityState entities = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_entities()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:GameState)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:GameState)
  return false;
#undef DO_
}

void GameState::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:GameState)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .EntityState entities = 1;
  for (unsigned int i = 0, n = this->entities_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->entities(i), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:GameState)
}

::google::protobuf::uint8* GameState::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:GameState)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .EntityState entities = 1;
  for (unsigned int i = 0, n = this->entities_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        1, this->entities(i), deterministic, target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:GameState)
  return target;
}

size_t GameState::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:GameState)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  // repeated .EntityState entities = 1;
  {
    unsigned int count = this->entities_size();
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->entities(i));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GameState::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:GameState)
  GOOGLE_DCHECK_NE(&from, this);
  const GameState* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const GameState>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:GameState)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:GameState)
    MergeFrom(*source);
  }
}

void GameState::MergeFrom(const GameState& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:GameState)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  entities_.MergeFrom(from.entities_);
}

void GameState::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:GameState)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameState::CopyFrom(const GameState& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:GameState)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameState::IsInitialized() const {
  if (!::google::protobuf::internal::AllAreInitialized(this->entities())) return false;
  return true;
}

void GameState::Swap(GameState* other) {
  if (other == this) return;
  InternalSwap(other);
}
void GameState::InternalSwap(GameState* other) {
  entities_.InternalSwap(&other->entities_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata GameState::GetMetadata() const {
  protobuf_GameState_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_GameState_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// GameState

// repeated .EntityState entities = 1;
int GameState::entities_size() const {
  return entities_.size();
}
void GameState::clear_entities() {
  entities_.Clear();
}
const ::EntityState& GameState::entities(int index) const {
  // @@protoc_insertion_point(field_get:GameState.entities)
  return entities_.Get(index);
}
::EntityState* GameState::mutable_entities(int index) {
  // @@protoc_insertion_point(field_mutable:GameState.entities)
  return entities_.Mutable(index);
}
::EntityState* GameState::add_entities() {
  // @@protoc_insertion_point(field_add:GameState.entities)
  return entities_.Add();
}
::google::protobuf::RepeatedPtrField< ::EntityState >*
GameState::mutable_entities() {
  // @@protoc_insertion_point(field_mutable_list:GameState.entities)
  return &entities_;
}
const ::google::protobuf::RepeatedPtrField< ::EntityState >&
GameState::entities() const {
  // @@protoc_insertion_point(field_list:GameState.entities)
  return entities_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
