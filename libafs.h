// Copyright (C) 2025 Thomas R. Dial. All rights reserved.
#ifndef LIBAFS_H_
#define LIBAFS_H_

#include <sys/types.h>

namespace afs {

class StreamInterface {
 public:
  virtual ~StreamInterface() {}
  virtual ssize_t PRead(unsigned char* buf, ssize_t count, ssize_t offset) = 0;
};

class Disk;
class Partition;
class Volume;
class File;

}  // namespace afs

#endif  // LIBAFS_H_
