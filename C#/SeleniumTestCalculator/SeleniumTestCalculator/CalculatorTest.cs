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
        [InlineData("1", "+", "0", "1")]
        [InlineData("1", "+", "1", "2")]
        [InlineData("1", "+", "2", "3")]
        [InlineData("1", "+", "3", "4")]
        [InlineData("1", "+", "4", "5")]
        [InlineData("1", "+", "5", "6")]
        [InlineData("1", "+", "6", "7")]
        [InlineData("1", "+", "7", "8")]
        [InlineData("1", "+", "8", "9")]
        [InlineData("1", "+", "9", "10")]
        [InlineData("0", "-", "0", "0")]
        [InlineData("9", "-", "0", "9")]
        [InlineData("9", "-", "9", "0")]
        [InlineData("9", "-", "8", "1")]
        [InlineData("9", "-", "7", "2")]
        [InlineData("9", "-", "6", "3")]
        [InlineData("9", "-", "5", "4")]
        [InlineData("9", "-", "4", "5")]
        [InlineData("9", "-", "3", "6")]
        [InlineData("9", "-", "2", "7")]
        [InlineData("9", "-", "1", "8")]
        [InlineData("0", "x", "0", "0")]
        [InlineData("2", "x", "1", "2")]
        [InlineData("2", "x", "2", "4")]
        [InlineData("2", "x", "3", "6")]
        [InlineData("2", "x", "4", "8")]
        [InlineData("2", "x", "5", "10")]
        [InlineData("2", "x", "6", "12")]
        [InlineData("2", "x", "7", "14")]
        [InlineData("2", "x", "8", "16")]
        [InlineData("2", "x", "9", "18")]
        [InlineData("0", "/", "0", "0")]
        [InlineData("2", "/", "1", "2")]
        [InlineData("2", "/", "2", "1")]
        [InlineData("2", "/", "4", "0.5")]
        [InlineData("2", "/", "5", "0,4")]
        [InlineData("2", "/", "8", "0,25")]
        public void TestAllNaturalNumbers(string arg1, string operation, string arg2, string result)
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
        [InlineData("0", "2", "+", "0", "1", "0.3")]
        [InlineData("0", "2", "-", "0", "1", "0.1")]
        [InlineData("2", "2", "+", "0", "1", "2.3")]
        [InlineData("8", "2", "+", "9", "3", "-1.1")]
        [InlineData("0", "2", "x", "5", "5", "1.1")]
        [InlineData("0", "2", "/", "0", "1", "2")]
        [InlineData("5", "5", "+", "2", "2", "12.1")]
        [InlineData("1", "0", "x", "1", "3", "1.3")]
        [InlineData("12", "2", "/", "0", "0", "Infinity")]

        public void TestAllRealNumbers(string arg11, string arg12, string operation, string arg21, string arg22, string result)
        {
            webDriver.FindElement(By.CssSelector(controls[arg11])).Click();
            Equal(arg11, webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["."])).Click();
            Equal(arg11 + ".", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls[arg12])).Click();
            Equal(arg11 + "." + arg12, webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls[operation])).Click();
            Equal(arg11 + "." + arg12 + operation, webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls[arg21])).Click();
            Equal(arg11 + "." + arg12 + operation + arg21, webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["."])).Click();
            Equal(arg11 + "." + arg12 + operation + arg21 + ".", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls[arg22])).Click();
            Equal(arg11 + "." + arg12 + operation + arg21 + "." + arg22, webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["="])).Click();
            Equal(result, webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
        }
    }
}