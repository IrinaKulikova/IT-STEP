using System;
using OpenQA.Selenium.Chrome;
using System.Collections.Generic;
using System.Text;
using OpenQA.Selenium;
using System.Diagnostics;
using System.IO;

namespace SeleniumTestCalculator
{
    //начальная инициализация перед каждым тестом и закрытие браузера
    public class BaseTest : IDisposable
    {
        protected readonly IWebDriver webDriver = new ChromeDriver(@"C:\Users\User\.nuget\packages\selenium.webdriver.chromedriver\2.43.0\driver\win32");
        protected readonly string url = @"file:///C:/Users/User/Documents/GitHub/IT-STEP/C%23/SeleniumTestCalculator/calculator.html";
        protected Dictionary<String, String> controls = new Dictionary<string, string>();
        
        public BaseTest()
        {
            controls.Add("1", "#calculator > div.keys > span:nth-child(9)");
            controls.Add("2", "#calculator > div.keys > span:nth-child(10)");
            controls.Add("3", "#calculator > div.keys > span:nth-child(11)");
            controls.Add("4", "#calculator > div.keys > span:nth-child(5)");
            controls.Add("5", "#calculator > div.keys > span:nth-child(6)");
            controls.Add("6", "#calculator > div.keys > span:nth-child(7)");
            controls.Add("7", "#calculator > div.keys > span:nth-child(1)");
            controls.Add("8", "#calculator > div.keys > span:nth-child(2)");
            controls.Add("9", "#calculator > div.keys > span:nth-child(3)");
            controls.Add("0", "#calculator > div.keys > span:nth-child(13)");
            controls.Add(".", "#calculator > div.keys > span:nth-child(14)");
            controls.Add("+", "#calculator > div.keys > span:nth-child(4)");
            controls.Add("-", "#calculator > div.keys > span:nth-child(8)");
            controls.Add("x", "#calculator > div.keys > span:nth-child(16)");
            controls.Add("/", "#calculator > div.keys > span:nth-child(12)");
            controls.Add("=", "#calculator > div.keys > span.eval");
            controls.Add("screen", "#calculator > div.top > div");

            webDriver.Url = url;
        }

        public void Dispose()
        {
            webDriver.Quit();
        }
    }
}
