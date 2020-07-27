#include "stdafx.h"
#include "CppUnitTest.h"
#include "../HW4/HashTable.h"
#include "../HW4/BinaryTree.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{		
	TEST_CLASS(Test)
	{
	public:
		
		TEST_METHOD(unitTest1)
		{
			int testNum = 41;
			HashTable *test = new HashTable();
			int testRet = test->insert(testNum);
			Assert::AreEqual(1, testRet);
			testRet = test->insert(testNum);
			Assert::AreEqual(2, testRet);
			testRet = test->insert(803);
			Assert::AreEqual(1, testRet);
			testRet = test->insert(testNum);
			Assert::AreEqual(3, testRet);
			delete test;
		}
		TEST_METHOD(unitTest2)
		{
			int testNum = 41;
			int testNum2 = 803;
			HashTable *test = new HashTable();
			int testRet = test->insert(testNum);
			test->insert(testNum);
			test->insert(testNum2);
			test->insert(testNum);

			int retVal = test->find(testNum);
			Assert::AreEqual(3, retVal);
			retVal = test->find(testNum2);
			Assert::AreEqual(1, retVal);
		}
		TEST_METHOD(unitTest3)
		{
			int testNum = 41;
			int testNum2 = 803;
			HashTable *test = new HashTable();
			int testRet = test->insert(testNum);
			test->insert(testNum);
			test->insert(testNum2);
			test->insert(testNum);

			int retVal = test->remove(testNum);
			Assert::AreEqual(1, retVal);
			retVal = test->remove(testNum2);
			Assert::AreEqual(1, retVal);
		}
		TEST_METHOD(unitTest4)
		{
			int testNum = 41;
			int testNum2 = 1505;
			int testNum3 = 45;
			int testNum4 = 47;
			searchTree test;
			int testRet = test.addNode(testNum);
			Assert::AreEqual(1, testRet);
			testRet = test.addNode(testNum2);
			Assert::AreEqual(1, testRet);
			testRet = test.addNode(testNum3);
			Assert::AreEqual(2, testRet);
			testRet = test.addNode(testNum4);
			Assert::AreEqual(3, testRet);

		}
		TEST_METHOD(unitTest5)
		{
			int testNum = 41;
			int testNum2 = 1505;
			int testNum3 = 45;
			int testNum4 = 47;
			searchTree *test = new searchTree();
			test->addNode(testNum);
			test->addNode(testNum2);
			test->addNode(testNum3);
			test->addNode(testNum4);
			
			int testRet = test->Find(testNum4);
			Assert::AreEqual(4, testRet);
			testRet = test->Find(testNum3);
			Assert::AreEqual(3, testRet);
			testRet = test->Find(testNum2);
			Assert::AreEqual(2, testRet);
			testRet = test->Find(testNum);
			Assert::AreEqual(1, testRet);
		}
		TEST_METHOD(unitTest6)
		{
			int testNum = 41;
			int testNum2 = 1505;
			int testNum3 = 45;
			int testNum4 = 47;
			searchTree *test = new searchTree();
			test->addNode(testNum);
			test->addNode(testNum2);
			test->addNode(testNum3);
			test->addNode(testNum4);

			int testRet = test->removeNode(testNum4);
			Assert::AreEqual(4, testRet);
			testRet = test->removeNode(testNum3);
			Assert::AreEqual(3, testRet);
			testRet = test->removeNode(testNum2);
			Assert::AreEqual(2, testRet);
			testRet = test->removeNode(testNum);
			Assert::AreEqual(1, testRet);
		}

	};
}