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
        
        public BaseTest()
        {
            Debug.Write(Directory.GetCurrentDirectory());
            webDriver.Url = url;
        }

        public void Dispose()
        {
            webDriver.Quit();
        }
    }
}
