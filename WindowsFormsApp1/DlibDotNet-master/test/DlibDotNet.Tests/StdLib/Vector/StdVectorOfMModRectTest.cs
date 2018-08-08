﻿using System.Linq;
using DlibDotNet.Tests;
using Microsoft.VisualStudio.TestTools.UnitTesting;

// ReSharper disable once CheckNamespace
namespace DlibDotNet
{

    [TestClass]
    public class StdVectorOfMModRectTest : TestBase
    {

        [TestMethod]
        public void Create()
        {
            var vector = new StdVector<MModRect>();
            this.DisposeAndCheckDisposedState(vector);
        }

        [TestMethod]
        public void CreateWithSize()
        {
            const int size = 10;
            var vector = new StdVector<MModRect>(size);
            this.DisposeAndCheckDisposedState(vector);
        }

        [TestMethod]
        public void CreateWithCollection()
        {
            const int size = 10;
            var source = Enumerable.Range(0, size).Select(i => new MModRect{Ignore = true, DetectionConfidence = i});
            var vector = new StdVector<MModRect>(source);
            Assert.AreEqual(vector.Size, size);
            var ret = vector.ToArray();
            for (var i = 0; i < size; i++)
            {
                Assert.AreEqual(ret[i].DetectionConfidence, i);
                Assert.AreEqual(ret[i].Ignore, true);
            }
            this.DisposeAndCheckDisposedState(vector);
        }

    }

}
