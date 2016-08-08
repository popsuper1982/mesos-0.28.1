# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

include(StoutConfigure)

if (NOT WIN32)
  find_package(Apr REQUIRED)
  find_package(Svn REQUIRED)
endif (NOT WIN32)

# Define process library dependencies. Tells the process library build targets
# download/configure/build all third-party libraries before attempting to build.
################################################################################
set(AGENT_DEPENDENCIES
  ${AGENT_DEPENDENCIES}
  ${PROCESS_DEPENDENCIES}
  ${PROCESS_TARGET}
  ${ZOOKEEPER_TARGET}
  ${LEVELDB_TARGET}
  make_bin_include_dir
  make_bin_src_dir
  )

# Define third-party include directories. Tells compiler toolchain where to get
# headers for our third party libs (e.g., -I/path/to/glog on Linux).
###############################################################################
set(AGENT_INCLUDE_DIRS
  ${AGENT_INCLUDE_DIRS}
  ${MESOS_PUBLIC_INCLUDE_DIR}
  # Contains (e.g.) compiled *.pb.h files.
  ${MESOS_BIN_INCLUDE_DIR}
  ${MESOS_BIN_INCLUDE_DIR}/mesos
  ${MESOS_BIN_SRC_DIR}
  ${MESOS_SRC_DIR}

  ${PROCESS_INCLUDE_DIRS}
  ${ZOOKEEPER_INCLUDE_DIR}
  ${ZOOKEEPER_INCLUDE_GENDIR}
  ${LEVELDB_INCLUDE_DIR}
  )

# Define third-party lib install directories. Used to tell the compiler
# toolchain where to find our third party libs (e.g., -L/path/to/glog on
# Linux).
########################################################################
set(AGENT_LIB_DIRS
  ${AGENT_LIB_DIRS}
  ${PROCESS_LIB_DIRS}
  ${ZOOKEEPER_LIB_DIR}
  )

# Define third-party libs. Used to generate flags that the linker uses to
# include our third-party libs (e.g., -lglog on Linux).
#########################################################################
set(AGENT_LIBS
  ${AGENT_LIBS}
  ${PROCESS_LIBS}
  ${ZOOKEEPER_LFLAG}
  ${PROCESS_TARGET}
  )

if (NOT WIN32)
  set(AGENT_LIBS
    ${AGENT_LIBS}
    ${LEVELDB_LFLAG}
    ${SASL_LFLAG}
    )
endif (NOT WIN32)

if (NOT ENABLE_LIBEVENT)
  set(AGENT_LIBS ${AGENT_LIBS} ${LIBEV_LFLAG})
elseif (ENABLE_LIBEVENT)
  set(AGENT_LIBS ${AGENT_LIBS} ${LIBEVENT_LFLAG})
endif (NOT ENABLE_LIBEVENT)
