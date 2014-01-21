/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013, 2014
              Vladimír Vondruš <mosra@centrum.cz>

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

#include <Corrade/TestSuite/Tester.h>

#include "Magnum/Math/Vector3.h"
#include "Magnum/Primitives/Icosphere.h"
#include "Magnum/Trade/MeshData3D.h"

namespace Magnum { namespace Primitives { namespace Test {

class IcosphereTest: public TestSuite::Tester {
    public:
        explicit IcosphereTest();

        void count();
};

IcosphereTest::IcosphereTest() {
    addTests<IcosphereTest>({&IcosphereTest::count});
}

void IcosphereTest::count() {
    Trade::MeshData3D data = Primitives::Icosphere::solid(2);

    CORRADE_COMPARE(data.positionArrayCount(), 1);
    CORRADE_COMPARE(data.normalArrayCount(), 1);

    CORRADE_COMPARE(data.indices().size(), 960);
    CORRADE_COMPARE(data.positions(0).size(), 162);
    CORRADE_COMPARE(data.normals(0).size(), 162);
}

}}}

CORRADE_TEST_MAIN(Magnum::Primitives::Test::IcosphereTest)