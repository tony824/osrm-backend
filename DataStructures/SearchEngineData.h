/*

Copyright (c) 2013, Project OSRM, Dennis Luxen, others
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list
of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this
list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef SEARCH_ENGINE_DATA_H
#define SEARCH_ENGINE_DATA_H

#ifndef SEARCH_ENGINE_DATA_H
#define SEARCH_ENGINE_DATA_H

#include "BinaryHeap.h"
#include "QueryEdge.h"
#include "StaticGraph.h"

#include "../typedefs.h"

#include <boost/thread.hpp>

#include <string>
#include <vector>

struct _HeapData {
    NodeID parent;
    _HeapData( NodeID p ) : parent(p) { }
};

// typedef StaticGraph<QueryEdge::EdgeData> QueryGraph;

struct SearchEngineData {
    typedef BinaryHeap< NodeID, NodeID, int, _HeapData, UnorderedMapStorage<NodeID, int> > QueryHeap;
    typedef boost::thread_specific_ptr<QueryHeap> SearchEngineHeapPtr;

    static SearchEngineHeapPtr forwardHeap;
    static SearchEngineHeapPtr backwardHeap;
    static SearchEngineHeapPtr forwardHeap2;
    static SearchEngineHeapPtr backwardHeap2;
    static SearchEngineHeapPtr forwardHeap3;
    static SearchEngineHeapPtr backwardHeap3;

    void InitializeOrClearFirstThreadLocalStorage(const unsigned number_of_nodes);

    void InitializeOrClearSecondThreadLocalStorage(const unsigned number_of_nodes);

    void InitializeOrClearThirdThreadLocalStorage(const unsigned number_of_nodes);
};

#endif // SEARCH_ENGINE_DATA_H
