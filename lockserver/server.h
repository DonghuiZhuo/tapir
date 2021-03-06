// -*- mode: c++; c-file-style: "k&r"; c-basic-offset: 4 -*-
/***********************************************************************
 *
 * lockserver/server.h:
 *   A lockserver replica interface.
 *
 * Copyright 2015 Naveen Kr. Sharma <naveenks@cs.washington.edu>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 **********************************************************************/

#ifndef _IR_LOCK_SERVER_H_
#define _IR_LOCK_SERVER_H_

#include "lib/udptransport.h"
#include "replication/ir/replica.h"
#include "lockserver/locks-proto.pb.h"

#include <string>
#include <unordered_map>

namespace lockserver {

class LockServer : public replication::ir::IRAppReplica
{
public:
    LockServer();
    ~LockServer();

    // Invoke inconsistent operation, no return value
    void ExecInconsistentUpcall(const string &str1);

    // Invoke consensus operation
    void ExecConsensusUpcall(const string &str1, string &str2);

    // Invoke unreplicated operation
    void UnloggedUpcall(const string &str1, string &str2);

private:
    std::unordered_map<std::string, uint64_t> locks;
};

} // namespace lockserver

#endif /* _IR_LOCK_SERVER_H_ */
