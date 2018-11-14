using OpenQA.Selenium;
using System;
using System.Threading;
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
            var button2 = "#calculator > div.keys > span:nth-child(10)";
            webDriver.FindElement(By.CssSelector(button2)).Click();
            var target = "#calculator > div.top > div";
            var actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2", actual);

            var plus = "#calculator > div.keys > span:nth-child(4)";
            webDriver.FindElement(By.CssSelector(plus)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2+", actual);

            var button4 = "#calculator > div.keys > span:nth-child(5)";
            webDriver.FindElement(By.CssSelector(button4)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2+4", actual);

            var result = "#calculator > div.keys > span.eval";
            webDriver.FindElement(By.CssSelector(result)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("6", actual);
            Thread.Sleep(2000);
        }

        [Fact]
        public void TestMinus()
        {
            var button2 = "#calculator > div.keys > span:nth-child(10)";
            webDriver.FindElement(By.CssSelector(button2)).Click();
            var target = "#calculator > div.top > div";
            var actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2", actual);

            var minus = "#calculator > div.keys > span:nth-child(8)";
            webDriver.FindElement(By.CssSelector(minus)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2-", actual);

            var button4 = "#calculator > div.keys > span:nth-child(5)";
            webDriver.FindElement(By.CssSelector(button4)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2-4", actual);

            var result = "#calculator > div.keys > span.eval";
            webDriver.FindElement(By.CssSelector(result)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("-2", actual);
            Thread.Sleep(2000);
        }

        [Fact]
        public void TestMulti()
        {
            var button2 = "#calculator > div.keys > span:nth-child(10)";
            webDriver.FindElement(By.CssSelector(button2)).Click();
            var target = "#calculator > div.top > div";
            var actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2", actual);

            var multy = "#calculator > div.keys > span:nth-child(16)";
            webDriver.FindElement(By.CssSelector(multy)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2x", actual);

            var button4 = "#calculator > div.keys > span:nth-child(5)";
            webDriver.FindElement(By.CssSelector(button4)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2x4", actual);

            var result = "#calculator > div.keys > span.eval";
            webDriver.FindElement(By.CssSelector(result)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("8", actual);
            Thread.Sleep(2000);
        }

        [Fact]
        public void TestDiv()
        {
            var button2 = "#calculator > div.keys > span:nth-child(10)";
            webDriver.FindElement(By.CssSelector(button2)).Click();
            var target = "#calculator > div.top > div";
            var actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2", actual);

            var div = "#calculator > div.keys > span:nth-child(12)";
            webDriver.FindElement(By.CssSelector(div)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2/", actual);

            var button1 = "#calculator > div.keys > span:nth-child(9)";
            webDriver.FindElement(By.CssSelector(button1)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2/1", actual);

            var result = "#calculator > div.keys > span.eval";
            webDriver.FindElement(By.CssSelector(result)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2", actual);
        }

        [Fact]
        public void TestDivNull()
        {
            var button2 = "#calculator > div.keys > span:nth-child(10)";
            webDriver.FindElement(By.CssSelector(button2)).Click();
            var target = "#calculator > div.top > div";
            var actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2", actual);

            var div = "#calculator > div.keys > span:nth-child(12)";
            webDriver.FindElement(By.CssSelector(div)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2/", actual);

            var button0 = "#calculator > div.keys > span:nth-child(13)";
            webDriver.FindElement(By.CssSelector(button0)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2/0", actual);

            var result = "#calculator > div.keys > span.eval";
            webDriver.FindElement(By.CssSelector(result)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("Infinity", actual);
        }

        [Fact]
        public void TestPlusRealNumbers()
        {
            var button2 = "#calculator > div.keys > span:nth-child(10)";
            webDriver.FindElement(By.CssSelector(button2)).Click();
            var target = "#calculator > div.top > div";
            var actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2", actual);

            var buttonDote = "#calculator > div.keys > span:nth-child(14)";
            webDriver.FindElement(By.CssSelector(buttonDote)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2.", actual);

            webDriver.FindElement(By.CssSelector(button2)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2.2", actual);

            var plus = "#calculator > div.keys > span:nth-child(4)";
            webDriver.FindElement(By.CssSelector(plus)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2.2+", actual);

            var button4 = "#calculator > div.keys > span:nth-child(5)";
            webDriver.FindElement(By.CssSelector(button4)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2.2+4", actual);

            webDriver.FindElement(By.CssSelector(buttonDote)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2.2+4.", actual);

            webDriver.FindElement(By.CssSelector(button4)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("2.2+4.4", actual);

            var result = "#calculator > div.keys > span.eval";
            webDriver.FindElement(By.CssSelector(result)).Click();
            actual = webDriver.FindElement(By.CssSelector(target)).Text;
            Equal("6.6", actual);
            Thread.Sleep(2000);
        }

        [Fact]
        public void TestMinusRealNumbers()
        {
        }

        [Fact]
        public void TestMultiRealNumbers()
        {
        }

        [Fact]
        public void TestDivRealNumbers()
        {
        }
    }
}