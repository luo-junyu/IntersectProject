#include "pch.h"
#include "CppUnitTest.h"
#include "..///IntersectProject/src/intersect.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectUnitTest
{
	TEST_CLASS(IntersectUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			struct Position point1;
			point1.x = 0.0000000001;
			point1.y = 5;
			struct Position point2;
			point2.x = -0.0000000001;;
			point2.y = 5;
			Assert::IsFalse(posCompare(point2, point1));
			Assert::IsFalse(posEqual(point1, point2));
			Assert::IsTrue(posEqual(point1, point1));
			Assert::IsFalse(posCompare(point1, point1));
		}
	};
}
