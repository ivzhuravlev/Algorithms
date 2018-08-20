using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using SingleElement;

namespace SingleElement.Tests
{
    [TestClass]
    public class SingleElementTests
    {
        [TestMethod]
        public void FindSingleIn4ElementsArray()
        {
            int[] array = { 3, 3, 2, 3 };
            Assert.AreEqual(2, SingleElement.FindSingleElement(array));
        }

        [TestMethod]
        public void FindSingleIn12ElementsArray()
        {
            int[] array = { 12, 1, 12, 3, 12, 1, 1, 5, 3, 3 };
            Assert.AreEqual(5, SingleElement.FindSingleElement(array));
        }
    }
}
