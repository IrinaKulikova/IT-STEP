using OpenQA.Selenium;
using Xunit;
using static Xunit.Assert;

namespace SeleniumTestCalculator
{
    //Написать тесткейсы для тестирования калькулятора с применением Selenium WebDriver
    public class CalculatorTest : BaseTest
    {

        [Fact]
        public void TestPlus()
        {
            webDriver.FindElement(By.CssSelector(controls["2"])).Click();
            Equal("2", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["+"])).Click();
            Equal("2+", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["4"])).Click();
            Equal("2+4", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["="])).Click();
            Equal("6", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
        }

        [Fact]
        public void TestMinus()
        {
            webDriver.FindElement(By.CssSelector(controls["2"])).Click();
            Equal("2", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["-"])).Click();
            Equal("2-", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["4"])).Click();
            Equal("2-4", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["="])).Click();
            Equal("-2", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
        }

        [Fact]
        public void TestMulti()
        {
            webDriver.FindElement(By.CssSelector(controls["2"])).Click();
            Equal("2", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["x"])).Click();
            Equal("2x", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["4"])).Click();
            Equal("2x4", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["="])).Click();
            Equal("8", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
        }

        [Fact]
        public void TestDiv()
        {
            webDriver.FindElement(By.CssSelector(controls["2"])).Click();
            Equal("2", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["/"])).Click();
            Equal("2/", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["1"])).Click();
            Equal("2/1", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["="])).Click();
            Equal("2", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
        }

        [Fact]
        public void TestDivNull()
        {
            webDriver.FindElement(By.CssSelector(controls["2"])).Click();
            Equal("2", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["/"])).Click();
            Equal("2/", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["0"])).Click();
            Equal("2/0", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["="])).Click();
            Equal("Infinity", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
        }

        [Fact]
        public void TestPlusRealNumbers()
        {
            webDriver.FindElement(By.CssSelector(controls["2"])).Click();
            Equal("2", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["."])).Click();
            Equal("2.", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["2"])).Click();
            Equal("2.2", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["+"])).Click();
            Equal("2.2+", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["4"])).Click();
            Equal("2.2+4", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["."])).Click();
            Equal("2.2+4.", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["4"])).Click();
            Equal("2.2+4.4", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["="])).Click();
            Equal("6.6", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
        }

        [Fact]
        public void TestMinusRealNumbers()
        {
            webDriver.FindElement(By.CssSelector(controls["2"])).Click();
            Equal("2", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["."])).Click();
            Equal("2.", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["2"])).Click();
            Equal("2.2", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["-"])).Click();
            Equal("2.2-", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["4"])).Click();
            Equal("2.2-4", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["."])).Click();
            Equal("2.2-4.", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["4"])).Click();
            Equal("2.2-4.4", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["="])).Click();
            Equal("-2.2", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
        }

        [Fact]
        public void TestMultiRealNumbers()
        {
            webDriver.FindElement(By.CssSelector(controls["2"])).Click();
            Equal("2", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["."])).Click();
            Equal("2.", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["2"])).Click();
            Equal("2.2", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["x"])).Click();
            Equal("2.2x", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["5"])).Click();
            Equal("2.2x5", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["."])).Click();
            Equal("2.2x5.", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["5"])).Click();
            Equal("2.2x5.5", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["="])).Click();
            Equal("12.1", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
        }

        [Fact]
        public void TestDivRealNumbers()
        {
            webDriver.FindElement(By.CssSelector(controls["2"])).Click();
            Equal("2", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["."])).Click();
            Equal("2.", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["2"])).Click();
            Equal("2.2", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["/"])).Click();
            Equal("2.2/", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["5"])).Click();
            Equal("2.2/5", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["."])).Click();
            Equal("2.2/5.", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["5"])).Click();
            Equal("2.2/5.5", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);

            webDriver.FindElement(By.CssSelector(controls["="])).Click();
            Equal("0.4", webDriver.FindElement(By.CssSelector(controls["screen"])).Text);
        }
    }
}