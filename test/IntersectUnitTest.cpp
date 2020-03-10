#include "pch.h"
#include "CppUnitTest.h"
#include "..///IntersectProject/src/intersect.h"
#include "..///IntersectProject/src/line.h"
#include "..///IntersectProject/src/line.cpp"
#include "..//IntersectProject/src/circle.h"
#include "..//IntersectProject/src/circle.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectUnitTest
{
	TEST_CLASS(IntersectUnitTest)
	{
	public:
		
		TEST_METHOD(posCompareTest1)
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

		TEST_METHOD(posCompareTest2)
		{
			struct Position point1;
			point1.x = 4;
			point1.y = -0.0000000001;
			struct Position point2;
			point2.x = 5;
			point2.y = 0.0000000001;
			Assert::IsFalse(posCompare(point1, point2));
			Assert::IsFalse(posEqual(point1, point2));
			Assert::IsTrue(posEqual(point1, point1));
			Assert::IsFalse(posCompare(point1, point1));
		}

		TEST_METHOD(posCompareTest3)
		{
			struct Position point1;
			point1.x = 5;
			point1.y = 0;
			struct Position point2;
			point2.x = 5;
			point2.y = 100;
			Assert::IsFalse(posCompare(point1, point2));
			Assert::IsTrue(posCompare(point2, point1));
			Assert::IsFalse(posEqual(point1, point2));
			Assert::IsTrue(posEqual(point2, point2));
			Assert::IsFalse(posCompare(point2, point2));
		}


		TEST_METHOD(LineTest1)
		{
			Line tmp1(0, 0, 1, 1);
			Line tmp2(1, 0, 0, 1);
			struct Position res = tmp1.intersect(tmp2);
			Assert::IsTrue(res.x == 0.5);
			Assert::IsTrue(res.y == 0.5);
		}

		TEST_METHOD(LineTest2)
		{
			Line tmp1(0, 0, 1, 1);
			Line tmp2(2, 0, 0, 2);
			struct Position res = tmp2.intersect(tmp1);
			Assert::IsTrue(res.x == 1);
			Assert::IsTrue(res.y == 1);
		}

		TEST_METHOD(LineTest3)
		{
			Line tmp1(1, 0, 1, 1);
			Line tmp2(0, 1, 1, 1);
			struct Position res = tmp2.intersect(tmp1);
			Assert::IsTrue(res.x == 1);
			Assert::IsTrue(res.y == 1);
		}

		TEST_METHOD(CircleTest1)
		{
			vector<struct Position> res;
			Line tmp1(0, 0, 5, 0);
			Circle tmp2(0, 0, 5);
			tmp2.lineIntersect(tmp1, res);
			Assert::IsTrue(res.size() == 2);
		}

		TEST_METHOD(CircleTest2)
		{
			vector<struct Position> res;
			Line tmp1(0, 0, 0, 5);
			Circle tmp2(0, 0, 5);
			tmp2.lineIntersect(tmp1, res);
			Assert::IsTrue(res.size() == 2);
		}

		TEST_METHOD(CircleTest3)
		{
			vector<struct Position> res;
			Line tmp1(5, 0, 5, 5);
			Circle tmp2(0, 5, 5);
			tmp2.lineIntersect(tmp1, res);
			Assert::IsTrue(res.size() == 1);
		}

		TEST_METHOD(CircleTest4)
		{
			vector<struct Position> res;
			Circle tmp1(4, 0, 2);
			Circle tmp2(0, 0, 2);
			tmp2.circleIntersect(tmp1, res);
			Assert::IsTrue(res.size() == 2);
		}

		TEST_METHOD(CircleTest5)
		{
			vector<struct Position> res;
			Circle tmp1(3, 0, 2);
			Circle tmp2(0, 0, 2);
			tmp2.circleIntersect(tmp1, res);
			Assert::IsTrue(res.size() == 2);
		}


		TEST_METHOD(CircleTest6)
		{
			vector<struct Position> res;
			Circle tmp1(5, 0, 2);
			Circle tmp2(0, 0, 2);
			tmp2.circleIntersect(tmp1, res);
			Assert::IsTrue(res.size() == 0);
		}

	};
}
