#include "test_main.h"

TEST(init, basic_constructor) {
  S21Matrix check;
  EXPECT_EQ(3, check.getRows());
  EXPECT_EQ(3, check.getCols());
}

TEST(init, parametrized_constructor_1) {
  S21Matrix check(64, 91);
  EXPECT_EQ(64, check.getRows());
  EXPECT_EQ(91, check.getCols());
}

TEST(init, parametrized_constructor_2) {
  S21Matrix check(22, 23);
  EXPECT_EQ(22, check.getRows());
  EXPECT_EQ(23, check.getCols());
}

TEST(init, parametrized_constructor_3) {
  S21Matrix check(90, 51);
  EXPECT_EQ(90, check.getRows());
  EXPECT_EQ(51, check.getCols());
}

TEST(init, parametrized_constructor_4) {
  S21Matrix check(82, 83);
  EXPECT_EQ(82, check.getRows());
  EXPECT_EQ(83, check.getCols());
}

TEST(init, parametrized_constructor_5) {
  S21Matrix check(52, 20);
  EXPECT_EQ(52, check.getRows());
  EXPECT_EQ(20, check.getCols());
}

TEST(init, parametrized_constructor_6) {
  S21Matrix check(14, 25);
  EXPECT_EQ(14, check.getRows());
  EXPECT_EQ(25, check.getCols());
}

TEST(init, parametrized_constructor_7) {
  S21Matrix check(62, 4);
  EXPECT_EQ(62, check.getRows());
  EXPECT_EQ(4, check.getCols());
}

TEST(init, parametrized_constructor_8) {
  S21Matrix check(3, 61);
  EXPECT_EQ(3, check.getRows());
  EXPECT_EQ(61, check.getCols());
}

TEST(init, parametrized_constructor_9) {
  S21Matrix check(39, 76);
  EXPECT_EQ(39, check.getRows());
  EXPECT_EQ(76, check.getCols());
}

TEST(init, parametrized_constructor_10) {
  S21Matrix check(57, 99);
  EXPECT_EQ(57, check.getRows());
  EXPECT_EQ(99, check.getCols());
}

TEST(init, parametrized_constructor_11) {
  S21Matrix check(62, 29);
  EXPECT_EQ(62, check.getRows());
  EXPECT_EQ(29, check.getCols());
}

TEST(init, parametrized_constructor_12) {
  S21Matrix check(41, 87);
  EXPECT_EQ(41, check.getRows());
  EXPECT_EQ(87, check.getCols());
}

TEST(init, parametrized_constructor_13) {
  S21Matrix check(61, 22);
  EXPECT_EQ(61, check.getRows());
  EXPECT_EQ(22, check.getCols());
}

TEST(init, parametrized_constructor_14) {
  S21Matrix check(43, 37);
  EXPECT_EQ(43, check.getRows());
  EXPECT_EQ(37, check.getCols());
}

TEST(init, parametrized_constructor_15) {
  S21Matrix check(61, 50);
  EXPECT_EQ(61, check.getRows());
  EXPECT_EQ(50, check.getCols());
}

TEST(init, parametrized_constructor_16) {
  S21Matrix check(43, 98);
  EXPECT_EQ(43, check.getRows());
  EXPECT_EQ(98, check.getCols());
}

TEST(init, parametrized_constructor_17) {
  S21Matrix check(75, 27);
  EXPECT_EQ(75, check.getRows());
  EXPECT_EQ(27, check.getCols());
}

TEST(init, parametrized_constructor_18) {
  S21Matrix check(80, 57);
  EXPECT_EQ(80, check.getRows());
  EXPECT_EQ(57, check.getCols());
}

TEST(init, parametrized_constructor_19) {
  S21Matrix check(60, 32);
  EXPECT_EQ(60, check.getRows());
  EXPECT_EQ(32, check.getCols());
}

TEST(init, parametrized_constructor_20) {
  S21Matrix check(30, 88);
  EXPECT_EQ(30, check.getRows());
  EXPECT_EQ(88, check.getCols());
}

TEST(init, parametrized_constructor_21) {
  S21Matrix check(87, 4);
  EXPECT_EQ(87, check.getRows());
  EXPECT_EQ(4, check.getCols());
}

TEST(init, parametrized_constructor_22) {
  S21Matrix check(64, 25);
  EXPECT_EQ(64, check.getRows());
  EXPECT_EQ(25, check.getCols());
}

TEST(init, parametrized_constructor_23) {
  S21Matrix check(67, 62);
  EXPECT_EQ(67, check.getRows());
  EXPECT_EQ(62, check.getCols());
}

TEST(init, parametrized_constructor_24) {
  S21Matrix check(67, 53);
  EXPECT_EQ(67, check.getRows());
  EXPECT_EQ(53, check.getCols());
}

TEST(init, parametrized_constructor_25) {
  S21Matrix check(77, 86);
  EXPECT_EQ(77, check.getRows());
  EXPECT_EQ(86, check.getCols());
}

TEST(init, parametrized_constructor_26) {
  S21Matrix check(94, 63);
  EXPECT_EQ(94, check.getRows());
  EXPECT_EQ(63, check.getCols());
}

TEST(init, parametrized_constructor_27) {
  S21Matrix check(25, 41);
  EXPECT_EQ(25, check.getRows());
  EXPECT_EQ(41, check.getCols());
}

TEST(init, parametrized_constructor_28) {
  S21Matrix check(3, 24);
  EXPECT_EQ(3, check.getRows());
  EXPECT_EQ(24, check.getCols());
}

TEST(init, parametrized_constructor_29) {
  S21Matrix check(64, 7);
  EXPECT_EQ(64, check.getRows());
  EXPECT_EQ(7, check.getCols());
}

TEST(init, parametrized_constructor_30) {
  S21Matrix check(55, 52);
  EXPECT_EQ(55, check.getRows());
  EXPECT_EQ(52, check.getCols());
}

TEST(init, parametrized_constructor_31) {
  S21Matrix check(70, 27);
  EXPECT_EQ(70, check.getRows());
  EXPECT_EQ(27, check.getCols());
}

TEST(init, parametrized_constructor_32) {
  S21Matrix check(47, 85);
  EXPECT_EQ(47, check.getRows());
  EXPECT_EQ(85, check.getCols());
}

TEST(init, parametrized_constructor_33) {
  S21Matrix check(85, 2);
  EXPECT_EQ(85, check.getRows());
  EXPECT_EQ(2, check.getCols());
}

TEST(init, parametrized_constructor_34) {
  S21Matrix check(78, 58);
  EXPECT_EQ(78, check.getRows());
  EXPECT_EQ(58, check.getCols());
}

TEST(init, parametrized_constructor_35) {
  EXPECT_THROW(S21Matrix(0, 58), std::out_of_range);
}

TEST(init, parametrized_constructor_36) {
  S21Matrix check(66, 41);
  EXPECT_EQ(66, check.getRows());
  EXPECT_EQ(41, check.getCols());
}

TEST(init, parametrized_constructor_37) {
  S21Matrix check(37, 95);
  EXPECT_EQ(37, check.getRows());
  EXPECT_EQ(95, check.getCols());
}

TEST(init, parametrized_constructor_38) {
  S21Matrix check(18, 64);
  EXPECT_EQ(18, check.getRows());
  EXPECT_EQ(64, check.getCols());
}

TEST(init, parametrized_constructor_39) {
  S21Matrix check(74, 28);
  EXPECT_EQ(74, check.getRows());
  EXPECT_EQ(28, check.getCols());
}

TEST(init, parametrized_constructor_40) {
  S21Matrix check(16, 24);
  EXPECT_EQ(16, check.getRows());
  EXPECT_EQ(24, check.getCols());
}

TEST(init, parametrized_constructor_41) {
  S21Matrix check(3, 52);
  EXPECT_EQ(3, check.getRows());
  EXPECT_EQ(52, check.getCols());
}

TEST(init, parametrized_constructor_42) {
  S21Matrix check(33, 62);
  EXPECT_EQ(33, check.getRows());
  EXPECT_EQ(62, check.getCols());
}

TEST(init, parametrized_constructor_43) {
  S21Matrix check(17, 92);
  EXPECT_EQ(17, check.getRows());
  EXPECT_EQ(92, check.getCols());
}

TEST(init, parametrized_constructor_44) {
  S21Matrix check(83, 8);
  EXPECT_EQ(83, check.getRows());
  EXPECT_EQ(8, check.getCols());
}

TEST(init, parametrized_constructor_45) {
  S21Matrix check(91, 54);
  EXPECT_EQ(91, check.getRows());
  EXPECT_EQ(54, check.getCols());
}

TEST(init, parametrized_constructor_46) {
  S21Matrix check(93, 26);
  EXPECT_EQ(93, check.getRows());
  EXPECT_EQ(26, check.getCols());
}

TEST(init, parametrized_constructor_47) {
  S21Matrix check(14, 3);
  EXPECT_EQ(14, check.getRows());
  EXPECT_EQ(3, check.getCols());
}

TEST(init, parametrized_constructor_48) {
  S21Matrix check(65, 52);
  EXPECT_EQ(65, check.getRows());
  EXPECT_EQ(52, check.getCols());
}

TEST(init, parametrized_constructor_49) {
  S21Matrix check(78, 17);
  EXPECT_EQ(78, check.getRows());
  EXPECT_EQ(17, check.getCols());
}

TEST(init, parametrized_constructor_50) {
  S21Matrix check(90, 8);
  EXPECT_EQ(90, check.getRows());
  EXPECT_EQ(8, check.getCols());
}

TEST(init, parametrized_constructor_51) {
  EXPECT_THROW(S21Matrix check(0, 0), std::out_of_range);
}

TEST(init, parametrized_constructor_52) {
  EXPECT_THROW(S21Matrix check(34, 0), std::out_of_range);
}

TEST(init, parametrized_constructor_53) {
  EXPECT_THROW(S21Matrix check(-28, 2), std::out_of_range);
}

TEST(init, parametrized_constructor_54) {
  EXPECT_THROW(S21Matrix check(-34, 4), std::out_of_range);
}

TEST(init, parametrized_constructor_55) {
  EXPECT_THROW(S21Matrix check(-34, -34), std::out_of_range);
}

TEST(init, copy_constructor_1_0) {
  S21Matrix tmp;
  S21Matrix check = tmp;
  EXPECT_EQ(3, check.getRows());
  EXPECT_EQ(3, check.getCols());
}

TEST(init, copy_constructor_1_1) {
  S21Matrix tmp(64, 91);
  S21Matrix check = tmp;
  EXPECT_EQ(64, check.getRows());
  EXPECT_EQ(91, check.getCols());
}

TEST(init, copy_constructor_1_2) {
  S21Matrix tmp(22, 23);
  S21Matrix check = tmp;
  EXPECT_EQ(22, check.getRows());
  EXPECT_EQ(23, check.getCols());
}

TEST(init, copy_constructor_1_3) {
  S21Matrix tmp(90, 51);
  S21Matrix check = tmp;
  EXPECT_EQ(90, check.getRows());
  EXPECT_EQ(51, check.getCols());
}

TEST(init, copy_constructor_1_4) {
  S21Matrix tmp(82, 83);
  S21Matrix check = tmp;
  EXPECT_EQ(82, check.getRows());
  EXPECT_EQ(83, check.getCols());
}

TEST(init, copy_constructor_1_5) {
  S21Matrix tmp(52, 20);
  S21Matrix check = tmp;
  EXPECT_EQ(52, check.getRows());
  EXPECT_EQ(20, check.getCols());
}

TEST(init, copy_constructor_1_6) {
  S21Matrix tmp(14, 25);
  S21Matrix check = tmp;
  EXPECT_EQ(14, check.getRows());
  EXPECT_EQ(25, check.getCols());
}

TEST(init, copy_constructor_1_7) {
  S21Matrix tmp(62, 4);
  S21Matrix check = tmp;
  EXPECT_EQ(62, check.getRows());
  EXPECT_EQ(4, check.getCols());
}

TEST(init, copy_constructor_1_8) {
  S21Matrix tmp(3, 61);
  S21Matrix check = tmp;
  EXPECT_EQ(3, check.getRows());
  EXPECT_EQ(61, check.getCols());
}

TEST(init, copy_constructor_1_9) {
  S21Matrix tmp(39, 76);
  S21Matrix check = tmp;
  EXPECT_EQ(39, check.getRows());
  EXPECT_EQ(76, check.getCols());
}

TEST(init, copy_constructor_1_10) {
  S21Matrix tmp(57, 99);
  S21Matrix check = tmp;
  EXPECT_EQ(57, check.getRows());
  EXPECT_EQ(99, check.getCols());
}

TEST(init, copy_constructor_1_11) {
  S21Matrix tmp(62, 29);
  S21Matrix check = tmp;
  EXPECT_EQ(62, check.getRows());
  EXPECT_EQ(29, check.getCols());
}

TEST(init, copy_constructor_1_12) {
  S21Matrix tmp(41, 87);
  S21Matrix check = tmp;
  EXPECT_EQ(41, check.getRows());
  EXPECT_EQ(87, check.getCols());
}

TEST(init, copy_constructor_1_13) {
  S21Matrix tmp(61, 22);
  S21Matrix check = tmp;
  EXPECT_EQ(61, check.getRows());
  EXPECT_EQ(22, check.getCols());
}

TEST(init, copy_constructor_1_14) {
  S21Matrix tmp(43, 37);
  S21Matrix check = tmp;
  EXPECT_EQ(43, check.getRows());
  EXPECT_EQ(37, check.getCols());
}

TEST(init, copy_constructor_1_15) {
  S21Matrix tmp(61, 50);
  S21Matrix check = tmp;
  EXPECT_EQ(61, check.getRows());
  EXPECT_EQ(50, check.getCols());
}

TEST(init, copy_constructor_1_16) {
  S21Matrix tmp(43, 98);
  S21Matrix check = tmp;
  EXPECT_EQ(43, check.getRows());
  EXPECT_EQ(98, check.getCols());
}

TEST(init, copy_constructor_1_17) {
  S21Matrix tmp(75, 27);
  S21Matrix check = tmp;
  EXPECT_EQ(75, check.getRows());
  EXPECT_EQ(27, check.getCols());
}

TEST(init, copy_constructor_1_18) {
  S21Matrix tmp(80, 57);
  S21Matrix check = tmp;
  EXPECT_EQ(80, check.getRows());
  EXPECT_EQ(57, check.getCols());
}

TEST(init, copy_constructor_1_19) {
  S21Matrix tmp(60, 32);
  S21Matrix check = tmp;
  EXPECT_EQ(60, check.getRows());
  EXPECT_EQ(32, check.getCols());
}

TEST(init, copy_constructor_1_20) {
  S21Matrix tmp(30, 88);
  S21Matrix check = tmp;
  EXPECT_EQ(30, check.getRows());
  EXPECT_EQ(88, check.getCols());
}

TEST(init, copy_constructor_1_21) {
  S21Matrix tmp(87, 4);
  S21Matrix check = tmp;
  EXPECT_EQ(87, check.getRows());
  EXPECT_EQ(4, check.getCols());
}

TEST(init, copy_constructor_1_22) {
  S21Matrix tmp(64, 25);
  S21Matrix check = tmp;
  EXPECT_EQ(64, check.getRows());
  EXPECT_EQ(25, check.getCols());
}

TEST(init, copy_constructor_1_23) {
  S21Matrix tmp(67, 62);
  S21Matrix check = tmp;
  EXPECT_EQ(67, check.getRows());
  EXPECT_EQ(62, check.getCols());
}

TEST(init, copy_constructor_1_24) {
  S21Matrix tmp(67, 53);
  S21Matrix check = tmp;
  EXPECT_EQ(67, check.getRows());
  EXPECT_EQ(53, check.getCols());
}

TEST(init, copy_constructor_1_25) {
  S21Matrix tmp(77, 86);
  S21Matrix check = tmp;
  EXPECT_EQ(77, check.getRows());
  EXPECT_EQ(86, check.getCols());
}

TEST(init, copy_constructor_1_26) {
  S21Matrix tmp(94, 63);
  S21Matrix check = tmp;
  EXPECT_EQ(94, check.getRows());
  EXPECT_EQ(63, check.getCols());
}

TEST(init, copy_constructor_1_27) {
  S21Matrix tmp(25, 41);
  S21Matrix check = tmp;
  EXPECT_EQ(25, check.getRows());
  EXPECT_EQ(41, check.getCols());
}

TEST(init, copy_constructor_1_28) {
  S21Matrix tmp(3, 24);
  S21Matrix check = tmp;
  EXPECT_EQ(3, check.getRows());
  EXPECT_EQ(24, check.getCols());
}

TEST(init, copy_constructor_1_29) {
  S21Matrix tmp(64, 7);
  S21Matrix check = tmp;
  EXPECT_EQ(64, check.getRows());
  EXPECT_EQ(7, check.getCols());
}

TEST(init, copy_constructor_1_30) {
  S21Matrix tmp(55, 52);
  S21Matrix check = tmp;
  EXPECT_EQ(55, check.getRows());
  EXPECT_EQ(52, check.getCols());
}

TEST(init, copy_constructor_1_31) {
  S21Matrix tmp(70, 27);
  S21Matrix check = tmp;
  EXPECT_EQ(70, check.getRows());
  EXPECT_EQ(27, check.getCols());
}

TEST(init, copy_constructor_1_32) {
  S21Matrix tmp(47, 85);
  S21Matrix check = tmp;
  EXPECT_EQ(47, check.getRows());
  EXPECT_EQ(85, check.getCols());
}

TEST(init, copy_constructor_1_33) {
  S21Matrix tmp(85, 2);
  S21Matrix check = tmp;
  EXPECT_EQ(85, check.getRows());
  EXPECT_EQ(2, check.getCols());
}

TEST(init, copy_constructor_1_34) {
  S21Matrix tmp(78, 58);
  S21Matrix check = tmp;
  EXPECT_EQ(78, check.getRows());
  EXPECT_EQ(58, check.getCols());
}

TEST(init, copy_constructor_1_35) {
  S21Matrix tmp(90, 8);
  S21Matrix check = tmp;
  EXPECT_EQ(90, check.getRows());
  EXPECT_EQ(8, check.getCols());
}

TEST(init, copy_constructor_1_36) {
  S21Matrix tmp(66, 41);
  S21Matrix check = tmp;
  EXPECT_EQ(66, check.getRows());
  EXPECT_EQ(41, check.getCols());
}

TEST(init, copy_constructor_1_37) {
  S21Matrix tmp(37, 95);
  S21Matrix check = tmp;
  EXPECT_EQ(37, check.getRows());
  EXPECT_EQ(95, check.getCols());
}

TEST(init, copy_constructor_1_38) {
  S21Matrix tmp(18, 64);
  S21Matrix check = tmp;
  EXPECT_EQ(18, check.getRows());
  EXPECT_EQ(64, check.getCols());
}

TEST(init, copy_constructor_1_39) {
  S21Matrix tmp(74, 28);
  S21Matrix check = tmp;
  EXPECT_EQ(74, check.getRows());
  EXPECT_EQ(28, check.getCols());
}

TEST(init, copy_constructor_1_40) {
  S21Matrix tmp(16, 24);
  S21Matrix check = tmp;
  EXPECT_EQ(16, check.getRows());
  EXPECT_EQ(24, check.getCols());
}

TEST(init, copy_constructor_1_41) {
  S21Matrix tmp(3, 52);
  S21Matrix check = tmp;
  EXPECT_EQ(3, check.getRows());
  EXPECT_EQ(52, check.getCols());
}

TEST(init, copy_constructor_1_42) {
  S21Matrix tmp(33, 62);
  S21Matrix check = tmp;
  EXPECT_EQ(33, check.getRows());
  EXPECT_EQ(62, check.getCols());
}

TEST(init, copy_constructor_1_43) {
  S21Matrix tmp(17, 92);
  S21Matrix check = tmp;
  EXPECT_EQ(17, check.getRows());
  EXPECT_EQ(92, check.getCols());
}

TEST(init, copy_constructor_1_44) {
  S21Matrix tmp(83, 8);
  S21Matrix check = tmp;
  EXPECT_EQ(83, check.getRows());
  EXPECT_EQ(8, check.getCols());
}

TEST(init, copy_constructor_1_45) {
  S21Matrix tmp(91, 54);
  S21Matrix check = tmp;
  EXPECT_EQ(91, check.getRows());
  EXPECT_EQ(54, check.getCols());
}

TEST(init, copy_constructor_1_46) {
  S21Matrix tmp(93, 26);
  S21Matrix check = tmp;
  EXPECT_EQ(93, check.getRows());
  EXPECT_EQ(26, check.getCols());
}

TEST(init, copy_constructor_1_47) {
  S21Matrix tmp(14, 3);
  S21Matrix check = tmp;
  EXPECT_EQ(14, check.getRows());
  EXPECT_EQ(3, check.getCols());
}

TEST(init, copy_constructor_1_48) {
  S21Matrix tmp(65, 52);
  S21Matrix check = tmp;
  EXPECT_EQ(65, check.getRows());
  EXPECT_EQ(52, check.getCols());
}

TEST(init, copy_constructor_1_49) {
  S21Matrix tmp(78, 17);
  S21Matrix check = tmp;
  EXPECT_EQ(78, check.getRows());
  EXPECT_EQ(17, check.getCols());
}

TEST(init, copy_constructor_4_0) {
  S21Matrix tmp;
  S21Matrix check(tmp);
  EXPECT_EQ(3, check.getRows());
  EXPECT_EQ(3, check.getCols());
}

TEST(init, copy_constructor_4_1) {
  S21Matrix tmp(64, 91);
  S21Matrix check(tmp);
  EXPECT_EQ(64, check.getRows());
  EXPECT_EQ(91, check.getCols());
}

TEST(init, copy_constructor_4_2) {
  S21Matrix tmp(22, 23);
  S21Matrix check(tmp);
  EXPECT_EQ(22, check.getRows());
  EXPECT_EQ(23, check.getCols());
}

TEST(init, copy_constructor_4_3) {
  S21Matrix tmp(90, 51);
  S21Matrix check(tmp);
  EXPECT_EQ(90, check.getRows());
  EXPECT_EQ(51, check.getCols());
}

TEST(init, copy_constructor_4_4) {
  S21Matrix tmp(82, 83);
  S21Matrix check(tmp);
  EXPECT_EQ(82, check.getRows());
  EXPECT_EQ(83, check.getCols());
}

TEST(init, copy_constructor_4_5) {
  S21Matrix tmp(52, 20);
  S21Matrix check(tmp);
  EXPECT_EQ(52, check.getRows());
  EXPECT_EQ(20, check.getCols());
}

TEST(init, copy_constructor_4_6) {
  S21Matrix tmp(14, 25);
  S21Matrix check(tmp);
  EXPECT_EQ(14, check.getRows());
  EXPECT_EQ(25, check.getCols());
}

TEST(init, copy_constructor_4_7) {
  S21Matrix tmp(62, 4);
  S21Matrix check(tmp);
  EXPECT_EQ(62, check.getRows());
  EXPECT_EQ(4, check.getCols());
}

TEST(init, copy_constructor_4_8) {
  S21Matrix tmp(3, 61);
  S21Matrix check(tmp);
  EXPECT_EQ(3, check.getRows());
  EXPECT_EQ(61, check.getCols());
}

TEST(init, copy_constructor_4_9) {
  S21Matrix tmp(39, 76);
  S21Matrix check(tmp);
  EXPECT_EQ(39, check.getRows());
  EXPECT_EQ(76, check.getCols());
}

TEST(init, copy_constructor_4_10) {
  S21Matrix tmp(57, 99);
  S21Matrix check(tmp);
  EXPECT_EQ(57, check.getRows());
  EXPECT_EQ(99, check.getCols());
}

TEST(init, copy_constructor_4_11) {
  S21Matrix tmp(62, 29);
  S21Matrix check(tmp);
  EXPECT_EQ(62, check.getRows());
  EXPECT_EQ(29, check.getCols());
}

TEST(init, copy_constructor_4_12) {
  S21Matrix tmp(41, 87);
  S21Matrix check(tmp);
  EXPECT_EQ(41, check.getRows());
  EXPECT_EQ(87, check.getCols());
}

TEST(init, copy_constructor_4_13) {
  S21Matrix tmp(61, 22);
  S21Matrix check(tmp);
  EXPECT_EQ(61, check.getRows());
  EXPECT_EQ(22, check.getCols());
}

TEST(init, copy_constructor_4_14) {
  S21Matrix tmp(43, 37);
  S21Matrix check(tmp);
  EXPECT_EQ(43, check.getRows());
  EXPECT_EQ(37, check.getCols());
}

TEST(init, copy_constructor_4_15) {
  S21Matrix tmp(61, 50);
  S21Matrix check(tmp);
  EXPECT_EQ(61, check.getRows());
  EXPECT_EQ(50, check.getCols());
}

TEST(init, copy_constructor_4_16) {
  S21Matrix tmp(43, 98);
  S21Matrix check(tmp);
  EXPECT_EQ(43, check.getRows());
  EXPECT_EQ(98, check.getCols());
}

TEST(init, copy_constructor_4_17) {
  S21Matrix tmp(75, 27);
  S21Matrix check(tmp);
  EXPECT_EQ(75, check.getRows());
  EXPECT_EQ(27, check.getCols());
}

TEST(init, copy_constructor_4_18) {
  S21Matrix tmp(80, 57);
  S21Matrix check(tmp);
  EXPECT_EQ(80, check.getRows());
  EXPECT_EQ(57, check.getCols());
}

TEST(init, copy_constructor_4_19) {
  S21Matrix tmp(60, 32);
  S21Matrix check(tmp);
  EXPECT_EQ(60, check.getRows());
  EXPECT_EQ(32, check.getCols());
}

TEST(init, copy_constructor_4_20) {
  S21Matrix tmp(30, 88);
  S21Matrix check(tmp);
  EXPECT_EQ(30, check.getRows());
  EXPECT_EQ(88, check.getCols());
}

TEST(init, copy_constructor_4_21) {
  S21Matrix tmp(87, 4);
  S21Matrix check(tmp);
  EXPECT_EQ(87, check.getRows());
  EXPECT_EQ(4, check.getCols());
}

TEST(init, copy_constructor_4_22) {
  S21Matrix tmp(64, 25);
  S21Matrix check(tmp);
  EXPECT_EQ(64, check.getRows());
  EXPECT_EQ(25, check.getCols());
}

TEST(init, copy_constructor_4_23) {
  S21Matrix tmp(67, 62);
  S21Matrix check(tmp);
  EXPECT_EQ(67, check.getRows());
  EXPECT_EQ(62, check.getCols());
}

TEST(init, copy_constructor_4_24) {
  S21Matrix tmp(67, 53);
  S21Matrix check(tmp);
  EXPECT_EQ(67, check.getRows());
  EXPECT_EQ(53, check.getCols());
}

TEST(init, copy_constructor_4_25) {
  S21Matrix tmp(77, 86);
  S21Matrix check(tmp);
  EXPECT_EQ(77, check.getRows());
  EXPECT_EQ(86, check.getCols());
}

TEST(init, copy_constructor_4_26) {
  S21Matrix tmp(94, 63);
  S21Matrix check(tmp);
  EXPECT_EQ(94, check.getRows());
  EXPECT_EQ(63, check.getCols());
}

TEST(init, copy_constructor_4_27) {
  S21Matrix tmp(25, 41);
  S21Matrix check(tmp);
  EXPECT_EQ(25, check.getRows());
  EXPECT_EQ(41, check.getCols());
}

TEST(init, copy_constructor_4_28) {
  S21Matrix tmp(3, 24);
  S21Matrix check(tmp);
  EXPECT_EQ(3, check.getRows());
  EXPECT_EQ(24, check.getCols());
}

TEST(init, copy_constructor_4_29) {
  S21Matrix tmp(64, 7);
  S21Matrix check(tmp);
  EXPECT_EQ(64, check.getRows());
  EXPECT_EQ(7, check.getCols());
}

TEST(init, copy_constructor_4_30) {
  S21Matrix tmp(55, 52);
  S21Matrix check(tmp);
  EXPECT_EQ(55, check.getRows());
  EXPECT_EQ(52, check.getCols());
}

TEST(init, copy_constructor_4_31) {
  S21Matrix tmp(70, 27);
  S21Matrix check(tmp);
  EXPECT_EQ(70, check.getRows());
  EXPECT_EQ(27, check.getCols());
}

TEST(init, copy_constructor_4_32) {
  S21Matrix tmp(47, 85);
  S21Matrix check(tmp);
  EXPECT_EQ(47, check.getRows());
  EXPECT_EQ(85, check.getCols());
}

TEST(init, copy_constructor_4_33) {
  S21Matrix tmp(85, 2);
  S21Matrix check(tmp);
  EXPECT_EQ(85, check.getRows());
  EXPECT_EQ(2, check.getCols());
}

TEST(init, copy_constructor_4_34) {
  S21Matrix tmp(78, 58);
  S21Matrix check(tmp);
  EXPECT_EQ(78, check.getRows());
  EXPECT_EQ(58, check.getCols());
}

TEST(init, copy_constructor_4_35) {
  S21Matrix tmp(90, 8);
  S21Matrix check(tmp);
  EXPECT_EQ(90, check.getRows());
  EXPECT_EQ(8, check.getCols());
}

TEST(init, copy_constructor_4_36) {
  S21Matrix tmp(66, 41);
  S21Matrix check(tmp);
  EXPECT_EQ(66, check.getRows());
  EXPECT_EQ(41, check.getCols());
}

TEST(init, copy_constructor_4_37) {
  S21Matrix tmp(37, 95);
  S21Matrix check(tmp);
  EXPECT_EQ(37, check.getRows());
  EXPECT_EQ(95, check.getCols());
}

TEST(init, copy_constructor_4_38) {
  S21Matrix tmp(18, 64);
  S21Matrix check(tmp);
  EXPECT_EQ(18, check.getRows());
  EXPECT_EQ(64, check.getCols());
}

TEST(init, copy_constructor_4_39) {
  S21Matrix tmp(74, 28);
  S21Matrix check(tmp);
  EXPECT_EQ(74, check.getRows());
  EXPECT_EQ(28, check.getCols());
}

TEST(init, copy_constructor_4_40) {
  S21Matrix tmp(16, 24);
  S21Matrix check(tmp);
  EXPECT_EQ(16, check.getRows());
  EXPECT_EQ(24, check.getCols());
}

TEST(init, copy_constructor_4_41) {
  S21Matrix tmp(3, 52);
  S21Matrix check(tmp);
  EXPECT_EQ(3, check.getRows());
  EXPECT_EQ(52, check.getCols());
}

TEST(init, copy_constructor_4_42) {
  S21Matrix tmp(33, 62);
  S21Matrix check(tmp);
  EXPECT_EQ(33, check.getRows());
  EXPECT_EQ(62, check.getCols());
}

TEST(init, copy_constructor_4_43) {
  S21Matrix tmp(17, 92);
  S21Matrix check(tmp);
  EXPECT_EQ(17, check.getRows());
  EXPECT_EQ(92, check.getCols());
}

TEST(init, copy_constructor_4_44) {
  S21Matrix tmp(83, 8);
  S21Matrix check(tmp);
  EXPECT_EQ(83, check.getRows());
  EXPECT_EQ(8, check.getCols());
}

TEST(init, copy_constructor_4_45) {
  S21Matrix tmp(91, 54);
  S21Matrix check(tmp);
  EXPECT_EQ(91, check.getRows());
  EXPECT_EQ(54, check.getCols());
}

TEST(init, copy_constructor_4_46) {
  S21Matrix tmp(93, 26);
  S21Matrix check(tmp);
  EXPECT_EQ(93, check.getRows());
  EXPECT_EQ(26, check.getCols());
}

TEST(init, copy_constructor_4_47) {
  S21Matrix tmp(14, 3);
  S21Matrix check(tmp);
  EXPECT_EQ(14, check.getRows());
  EXPECT_EQ(3, check.getCols());
}

TEST(init, copy_constructor_4_48) {
  S21Matrix tmp(65, 52);
  S21Matrix check(tmp);
  EXPECT_EQ(65, check.getRows());
  EXPECT_EQ(52, check.getCols());
}

TEST(init, copy_constructor_4_49) {
  S21Matrix tmp(78, 17);
  S21Matrix check(tmp);
  EXPECT_EQ(78, check.getRows());
  EXPECT_EQ(17, check.getCols());
}

TEST(init, move_constructor_0) {
  S21Matrix tmp;
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(3, check.getRows());
  EXPECT_EQ(3, check.getCols());
}

TEST(init, move_constructor_1) {
  S21Matrix tmp(64, 91);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(64, check.getRows());
  EXPECT_EQ(91, check.getCols());
}

TEST(init, move_constructor_2) {
  S21Matrix tmp(22, 23);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(22, check.getRows());
  EXPECT_EQ(23, check.getCols());
}

TEST(init, move_constructor_3) {
  S21Matrix tmp(90, 51);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(90, check.getRows());
  EXPECT_EQ(51, check.getCols());
}

TEST(init, move_constructor_4) {
  S21Matrix tmp(82, 83);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(82, check.getRows());
  EXPECT_EQ(83, check.getCols());
}

TEST(init, move_constructor_5) {
  S21Matrix tmp(52, 20);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(52, check.getRows());
  EXPECT_EQ(20, check.getCols());
}

TEST(init, move_constructor_6) {
  S21Matrix tmp(14, 25);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(14, check.getRows());
  EXPECT_EQ(25, check.getCols());
}

TEST(init, move_constructor_7) {
  S21Matrix tmp(62, 4);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(62, check.getRows());
  EXPECT_EQ(4, check.getCols());
}

TEST(init, move_constructor_8) {
  S21Matrix tmp(3, 61);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(3, check.getRows());
  EXPECT_EQ(61, check.getCols());
}

TEST(init, move_constructor_9) {
  S21Matrix tmp(39, 76);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(39, check.getRows());
  EXPECT_EQ(76, check.getCols());
}

TEST(init, move_constructor_10) {
  S21Matrix tmp(57, 99);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(57, check.getRows());
  EXPECT_EQ(99, check.getCols());
}

TEST(init, move_constructor_11) {
  S21Matrix tmp(62, 29);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(62, check.getRows());
  EXPECT_EQ(29, check.getCols());
}

TEST(init, move_constructor_12) {
  S21Matrix tmp(41, 87);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(41, check.getRows());
  EXPECT_EQ(87, check.getCols());
}

TEST(init, move_constructor_13) {
  S21Matrix tmp(61, 22);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(61, check.getRows());
  EXPECT_EQ(22, check.getCols());
}

TEST(init, move_constructor_14) {
  S21Matrix tmp(43, 37);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(43, check.getRows());
  EXPECT_EQ(37, check.getCols());
}

TEST(init, move_constructor_15) {
  S21Matrix tmp(61, 50);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(61, check.getRows());
  EXPECT_EQ(50, check.getCols());
}

TEST(init, move_constructor_16) {
  S21Matrix tmp(43, 98);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(43, check.getRows());
  EXPECT_EQ(98, check.getCols());
}

TEST(init, move_constructor_17) {
  S21Matrix tmp(75, 27);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(75, check.getRows());
  EXPECT_EQ(27, check.getCols());
}

TEST(init, move_constructor_18) {
  S21Matrix tmp(80, 57);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(80, check.getRows());
  EXPECT_EQ(57, check.getCols());
}

TEST(init, move_constructor_19) {
  S21Matrix tmp(60, 32);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(60, check.getRows());
  EXPECT_EQ(32, check.getCols());
}

TEST(init, move_constructor_20) {
  S21Matrix tmp(30, 88);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(30, check.getRows());
  EXPECT_EQ(88, check.getCols());
}

TEST(init, move_constructor_21) {
  S21Matrix tmp(87, 4);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(87, check.getRows());
  EXPECT_EQ(4, check.getCols());
}

TEST(init, move_constructor_22) {
  S21Matrix tmp(64, 25);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(64, check.getRows());
  EXPECT_EQ(25, check.getCols());
}

TEST(init, move_constructor_23) {
  S21Matrix tmp(67, 62);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(67, check.getRows());
  EXPECT_EQ(62, check.getCols());
}

TEST(init, move_constructor_24) {
  S21Matrix tmp(67, 53);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(67, check.getRows());
  EXPECT_EQ(53, check.getCols());
}

TEST(init, move_constructor_25) {
  S21Matrix tmp(77, 86);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(77, check.getRows());
  EXPECT_EQ(86, check.getCols());
}

TEST(init, move_constructor_26) {
  S21Matrix tmp(94, 63);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(94, check.getRows());
  EXPECT_EQ(63, check.getCols());
}

TEST(init, move_constructor_27) {
  S21Matrix tmp(25, 41);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(25, check.getRows());
  EXPECT_EQ(41, check.getCols());
}

TEST(init, move_constructor_28) {
  S21Matrix tmp(3, 24);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(3, check.getRows());
  EXPECT_EQ(24, check.getCols());
}

TEST(init, move_constructor_29) {
  S21Matrix tmp(64, 7);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(64, check.getRows());
  EXPECT_EQ(7, check.getCols());
}

TEST(init, move_constructor_30) {
  S21Matrix tmp(55, 52);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(55, check.getRows());
  EXPECT_EQ(52, check.getCols());
}

TEST(init, move_constructor_31) {
  S21Matrix tmp(70, 27);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(70, check.getRows());
  EXPECT_EQ(27, check.getCols());
}

TEST(init, move_constructor_32) {
  S21Matrix tmp(47, 85);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(47, check.getRows());
  EXPECT_EQ(85, check.getCols());
}

TEST(init, move_constructor_33) {
  S21Matrix tmp(85, 2);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(85, check.getRows());
  EXPECT_EQ(2, check.getCols());
}

TEST(init, move_constructor_34) {
  S21Matrix tmp(78, 58);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(78, check.getRows());
  EXPECT_EQ(58, check.getCols());
}

TEST(init, move_constructor_35) {
  S21Matrix tmp(90, 8);
  S21Matrix check(tmp);
  EXPECT_EQ(90, check.getRows());
  EXPECT_EQ(8, check.getCols());
}

TEST(init, move_constructor_36) {
  S21Matrix tmp(66, 41);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(66, check.getRows());
  EXPECT_EQ(41, check.getCols());
}

TEST(init, move_constructor_37) {
  S21Matrix tmp(37, 95);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(37, check.getRows());
  EXPECT_EQ(95, check.getCols());
}

TEST(init, move_constructor_38) {
  S21Matrix tmp(18, 64);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(18, check.getRows());
  EXPECT_EQ(64, check.getCols());
}

TEST(init, move_constructor_39) {
  S21Matrix tmp(74, 28);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(74, check.getRows());
  EXPECT_EQ(28, check.getCols());
}

TEST(init, move_constructor_40) {
  S21Matrix tmp(16, 24);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(16, check.getRows());
  EXPECT_EQ(24, check.getCols());
}

TEST(init, move_constructor_41) {
  S21Matrix tmp(3, 52);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(3, check.getRows());
  EXPECT_EQ(52, check.getCols());
}

TEST(init, move_constructor_42) {
  S21Matrix tmp(33, 62);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(33, check.getRows());
  EXPECT_EQ(62, check.getCols());
}

TEST(init, move_constructor_43) {
  S21Matrix tmp(17, 92);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(17, check.getRows());
  EXPECT_EQ(92, check.getCols());
}

TEST(init, move_constructor_44) {
  S21Matrix tmp(83, 8);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(83, check.getRows());
  EXPECT_EQ(8, check.getCols());
}

TEST(init, move_constructor_45) {
  S21Matrix tmp(91, 54);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(91, check.getRows());
  EXPECT_EQ(54, check.getCols());
}

TEST(init, move_constructor_46) {
  S21Matrix tmp(93, 26);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(93, check.getRows());
  EXPECT_EQ(26, check.getCols());
}

TEST(init, move_constructor_47) {
  S21Matrix tmp(14, 3);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(14, check.getRows());
  EXPECT_EQ(3, check.getCols());
}

TEST(init, move_constructor_48) {
  S21Matrix tmp(65, 52);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(65, check.getRows());
  EXPECT_EQ(52, check.getCols());
}

TEST(init, move_constructor_49) {
  S21Matrix tmp(78, 17);
  S21Matrix check(std::move(tmp));
  EXPECT_EQ(78, check.getRows());
  EXPECT_EQ(17, check.getCols());
}
