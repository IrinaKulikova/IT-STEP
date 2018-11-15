using OpenQA.Selenium;
using Xunit;
using static Xunit.Assert;

namespace SeleniumTestCalculator
{
    //Написать тесткейсы для тестирования калькулятора с приминением Selenium WebDriver
    public class CalculatorTest : BaseTest
    {
        [Theory]
        [InlineData("0", "+", "0", "0")]
        [InlineData("1", "+", "9", "10")]
        [InlineData("0", "-", "0", "0")]
        [InlineData("9", "-", "2", "7")]
        [InlineData("9", "-", "1", "8")]
        [InlineData("0", "x", "0", "0")]
        [InlineData("2", "x", "9", "18")]
        [InlineData("0", "/", "0", "NaN")]
        [InlineData("8", "/", "2", "4")]
        [InlineData("4", "/", "8", "1")]
        [InlineData("0", "/", "3", "NaN")]
        [InlineData("2", "/", "1", "2")]
        [InlineData("2", "/", "8", "0.25")]
        public void TestNaturalNumbers(string arg1, string operation, string arg2, string result)
        {
            webDriver.FindElement(By.CssSelector(controls[arg1])).Click();
            Equal(arg1, webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls[operation])).Click();
            Equal(arg1 + operation, webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls[arg2])).Click();
            Equal(arg1 + operation + arg2, webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["="])).Click();
            Equal(result, webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
        }


        [Theory]
        [InlineData("2047483647", "+", "96857432", "2144341079")]
        [InlineData("2147483647", "-", "96857432", "2050626215")]
        [InlineData("214748364", "x", "2", "429496728")]
        [InlineData("2147483640", "/", "10", "214748364")]
        public void TestNaturalBigNumbers(string arg1, string operation, string arg2, string result)
        {
            for (int i = 0; i < arg1.Length; i++)
            {
                webDriver.FindElement(By.CssSelector(controls[arg1[i].ToString()])).Click();
                Equal(arg1.Substring(0, i + 1), webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
            }

            webDriver.FindElement(By.CssSelector(controls[operation])).Click();
            Equal(arg1 + operation, webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            for (int i = 0; i < arg2.Length; i++)
            {
                webDriver.FindElement(By.CssSelector(controls[arg2[i].ToString()])).Click();
                Equal(arg1 + operation + arg2.Substring(0, i + 1), webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
            }

            webDriver.FindElement(By.CssSelector(controls["="])).Click();
            Equal(result, webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
        }

        [Theory]
        [InlineData("0.2", "+", "0.1", "0.3")]
        [InlineData("0.2", "-", "0.1", "0.1")]
        [InlineData("2.2", "+", "0.1", "2.3")]
        [InlineData("8.2", "+", "9.3", "-1.1")]
        [InlineData("0.2", "x", "5.5", "1.1")]
        [InlineData("0.2", "/", "0.1", "2")]
        [InlineData("5.5", "+", "2.2", "12.1")]
        [InlineData("1.0", "x", "1.3", "1.3")]
        [InlineData("12.2", "/", "0.0", "Infinity")]
        [InlineData("2047483647.003", "+", "96857432.02", "2144341079.023")]
        [InlineData("0.000007", "-", "0.00000008", "0.00000692")]
        [InlineData("0.00001", "x", "0.001", "1e-8")]
        [InlineData("0.0000001", "/", "0.000001", "0.1")]
        [InlineData("-0.0000001", "/", "0.000001", "-0.1")]
        [InlineData("0.01", "/", "100", "0.001")]
        public void TestRealBigAndSmallNumbers(string arg1, string operation, string arg2, string result)
        {
            for (int i = 0; i < arg1.Length; i++)
            {
                webDriver.FindElement(By.CssSelector(controls[arg1[i].ToString()])).Click();
                Equal(arg1.Substring(0, i + 1), webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
            }

            webDriver.FindElement(By.CssSelector(controls[operation])).Click();
            Equal(arg1 + operation, webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            for (int i = 0; i < arg2.Length; i++)
            {
                webDriver.FindElement(By.CssSelector(controls[arg2[i].ToString()])).Click();
                Equal(arg1 + operation + arg2.Substring(0, i + 1), webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
            }

            webDriver.FindElement(By.CssSelector(controls["="])).Click();
            Equal(result, webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
        }


        [Theory]
        [InlineData("-2047483647.003", "+-+-", "0.3", "-2047483647.303")]
        [InlineData("-0.000007", "-", "0.0000008", "-0.0000078")]
        [InlineData("-0.00001", "x-x", "0.001", "-1e-8")]
        [InlineData("-0.0000001", "/", "0.000001", "-0.1")]
        [InlineData("-0.0000001", "/+", "0.000001", "9e-7")]
        [InlineData("-0.01", "/+-", "100", "-100.01")]
        public void TestOperators(string arg1, string operation, string arg2, string result)
        {
            for (int i = 0; i < arg1.Length; i++)
            {
                webDriver.FindElement(By.CssSelector(controls[arg1[i].ToString()])).Click();
                Equal(arg1.Substring(0, i + 1), webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
            }

            for (int i = 0; i < operation.Length; i++)
            {
                webDriver.FindElement(By.CssSelector(controls[operation[i].ToString()])).Click();
                Equal(arg1 + operation[i], webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
            }

            for (int i = 0; i < arg2.Length; i++)
            {
                webDriver.FindElement(By.CssSelector(controls[arg2[i].ToString()])).Click();
                Equal(arg1 + operation[operation.Length - 1] + arg2.Substring(0, i + 1), webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
            }

            webDriver.FindElement(By.CssSelector(controls["="])).Click();
            Equal(result, webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
        }
    }
}