//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// SPDX-FileCopyrightText: Copyright (c) 2023 NVIDIA CORPORATION & AFFILIATES.
//
//===----------------------------------------------------------------------===//

// <vector>

// Call front() on empty const container.

// REQUIRES: has-unix-headers
// UNSUPPORTED: c++03
// XFAIL: use_system_cxx_lib && target={{.+}}-apple-macosx{{10.9|10.10|10.11|10.12|10.13|10.14|10.15|11.0|12.0}}
// ADDITIONAL_COMPILE_FLAGS: -D_LIBCUDACXX_ENABLE_ASSERTIONS=1
#define _LIBCUDACXX_ENABLE_ASSERTIONS 1

#include <vector>

#include "check_assertion.h"
#include "min_allocator.h"

int main(int, char**) {
  {
    typedef int T;
    typedef std::vector<T, min_allocator<T> > C;
    const C c;
    TEST_LIBCUDACXX_ASSERT_FAILURE(c.front(), "front() called on an empty vector");
  }

  {
    typedef int T;
    typedef std::vector<T> C;
    const C c;
    TEST_LIBCUDACXX_ASSERT_FAILURE(c.front(), "front() called on an empty vector");
  }

  return 0;
}
