#include <gtest/gtest.h>
#include <gadget/error.h>

using namespace gget;

TEST(GadgetError, NoCheckDeath) { ASSERT_DEBUG_DEATH(Error err(Error::NoError), ""); }

TEST(GadgetError, CheckNoDeath) {
    ASSERT_NO_FATAL_FAILURE({
        Error err(Error::NoError);
        const bool check = err;
    });
}

TEST(GadgetError, NoAssertOnMove) {
    ASSERT_NO_FATAL_FAILURE({
        Error err0(Error::NoError);

        Error err1       = std::move(err0);
        const bool check = err1;
    });
}

TEST(GadgetError, NoAssertOnEquality) {
    ASSERT_NO_FATAL_FAILURE({
        const Error err0(Error::NoError);

        const bool result = err0 == 0;
    });
}

TEST(GadgetError, NoAssertOnInEquality) {
    ASSERT_NO_FATAL_FAILURE({
        const Error err0(Error::NoError);

        const bool result = err0 != 0;
    });
}

TEST(GadgetError, CheckNoErrorCode) {
    const Error err(Error::NoError);

    const bool result = err;

    ASSERT_FALSE(result);
}

TEST(GadgetError, CheckErrorCode) {
    const Error err(123);

    const bool result = err;

    ASSERT_EQ(err.GetCode(), 123);
}

TEST(GadgetError, CheckErrorCodeOnMove) {
    Error err0(123);

    Error err1        = std::move(err0);
    const bool result = err1;

    ASSERT_EQ(err1.GetCode(), 123);
}

TEST(GadgetError, CheckErrorCodeMessage) {
    const Error err(123, "Error Happened");

    const bool result = err;

    EXPECT_EQ(err.GetCode(), 123);
    EXPECT_STRCASEEQ(err.GetMessage(), "Error Happened");
}

TEST(GadgetError, CheckErrorCodeMessageOnMove) {
    Error err0(123, "Error Happened");

    Error err1        = std::move(err0);
    const bool result = err1;

    EXPECT_EQ(err1.GetCode(), 123);
    EXPECT_STRCASEEQ(err1.GetMessage(), "Error Happened");
}

TEST(GadgetError, CheckAllValues) {
    const auto line = __LINE__;
    const Error err(123, "Error Happened", line, __FILE__);

    const bool result = err;

    EXPECT_EQ(err.GetCode(), 123);
    EXPECT_STRCASEEQ(err.GetMessage(), "Error Happened");
    EXPECT_EQ(err.GetLine(), line);
    EXPECT_STRCASEEQ(err.GetFileName(), __FILE__);
}

TEST(GadgetError, CheckAllValuesOnMove) {
    const auto line = __LINE__;
    Error err0(123, "Error Happened", line, __FILE__);

    Error err1        = std::move(err0);
    const bool result = err1;

    EXPECT_EQ(err1.GetCode(), 123);
    EXPECT_STRCASEEQ(err1.GetMessage(), "Error Happened");
    EXPECT_EQ(err1.GetLine(), line);
    EXPECT_STRCASEEQ(err1.GetFileName(), __FILE__);
}
