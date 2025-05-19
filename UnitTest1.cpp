#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../Project2/lab.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace StringProcessTests
{
    TEST_CLASS(UnitTest_StringProcess)
    {
    public:

        TEST_METHOD(TestExtractPrefix_NoSpace)
        {
            string s = "HelloWorld";
            Assert::AreEqual(string("HelloWorld"), ExtractPrefix(s));
        }

        TEST_METHOD(TestExtractPrefix_WithSpace)
        {
            string s = "Abc123 def456";
            Assert::AreEqual(string("Abc123"), ExtractPrefix(s));
        }

        TEST_METHOD(TestNormalize_AllValid)
        {
            string seg = "A1b2C3";
            Assert::AreEqual(string("a1b2c3"), Normalize(seg));
        }

        TEST_METHOD(TestNormalize_WithPunct)
        {
            string seg = "X!@#4Y$%^z";
            Assert::AreEqual(string("x4yz"), Normalize(seg));
        }

        TEST_METHOD(TestIntegration_PrefixAndNormalize)
        {
            string s = "Te5t!# Case ";
            string pref = ExtractPrefix(s);
            string norm = Normalize(pref);
            Assert::AreEqual(string("te5t"), norm);
        }
    };
}
