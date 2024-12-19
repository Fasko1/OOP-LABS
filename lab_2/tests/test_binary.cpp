#include <gtest/gtest.h>
#include "../include/binary.h"

TEST(BinaryTest, DefaultConstructor)
{
    Binary b;

    size_t size = b.getSize();
    const unsigned char *data = b.getData();

    EXPECT_EQ(size, 0);
    EXPECT_EQ(data, nullptr);
}

TEST(BinaryTest, SizeAndDefaultConstructor)
{
    size_t n = 5;
    unsigned char value = '0';
    Binary b(n, value);

    size_t size = b.getSize();
    unsigned char *data = b.getData();

    EXPECT_EQ(size, n);
    for (size_t i = 0; i < size; ++i)
    {
        EXPECT_EQ(data[i], value);
    }
}

TEST(BinaryTest, InitializerListConstructor)
{
    std::initializer_list<unsigned char> values = {'1', '0', '1', '1'};
    Binary b(values);

    size_t size = b.getSize();
    unsigned char *data = b.getData();

    EXPECT_EQ(size, values.size());
    size_t i = 0;
    for (unsigned char digit : values)
    {
        EXPECT_EQ(data[i++], digit);
    }
}

TEST(BinaryTest, StringConstructor)
{
    std::string str = "1011";
    Binary b(str);

    size_t size = b.getSize();
    unsigned char *data = b.getData();

    EXPECT_EQ(size, str.size());
    for (size_t i = 0; i < size; ++i)
    {
        EXPECT_EQ(data[i], str[i]);
    }
}

TEST(BinaryTest, AssignmentOperator)
{
    Binary b1("1011");
    Binary b2 = b1;

    EXPECT_TRUE(b1.eq(b2));
}

TEST(BinaryTest, Addition)
{
    Binary b1("1010");
    Binary b2("1101");

    b1.add(b2);

    std::string expected = "10111"; // Ожидаемый результат сложения
    EXPECT_EQ(b1.getSize(), expected.size());
    for (size_t i = 0; i < b1.getSize(); ++i)
    {
        EXPECT_EQ(b1.getData()[i], expected[i]);
    }
}

TEST(BinaryTest, Subtraction)
{
    Binary b1("11111");
    Binary b2("00011");

    b1.sub(b2);

    std::string expected = "11100"; // Ожидаемый результат вычитания
    EXPECT_EQ(b1.getSize(), expected.size());
    for (size_t i = 0; i < b1.getSize(); ++i)
    {
        EXPECT_EQ(b1.getData()[i], expected[i]);
    }
}

TEST(BinaryTest, Equality)
{
    Binary b1("1010");
    Binary b2("1010");
    Binary b3("1101");

    EXPECT_TRUE(b1.eq(b2));
    EXPECT_FALSE(b1.eq(b3));
}

TEST(BinaryTest, LessThan)
{
    Binary b1("1010");
    Binary b2("1101");

    EXPECT_TRUE(b1.le(b2));
    EXPECT_FALSE(b2.le(b1));
}

TEST(BinaryTest, GreaterThan)
{
    Binary b1("1101");
    Binary b2("1010");

    EXPECT_TRUE(b1.ge(b2));
    EXPECT_FALSE(b2.ge(b1));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}