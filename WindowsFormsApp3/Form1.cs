using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Timers;
namespace WindowsFormsApp3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            init();
            
        }
        IEnumerable<string> sites;
        int counter = 0;

        private void init()
        {
            nav();
        }





        private async Task PageLoad(int TimeOut)
        {
            TaskCompletionSource<bool> PageLoaded = null;
            PageLoaded = new TaskCompletionSource<bool>();
            int TimeElapsed = 0;
            webBrowser1.DocumentCompleted += (s, e) =>
            {
                if (webBrowser1.ReadyState != WebBrowserReadyState.Complete) return;
                if (PageLoaded.Task.IsCompleted)
                {
                    navigeUrl(sites.ElementAt(counter++ % (sites.Count() - 1)));
                    return;
                }
                PageLoaded.SetResult(true);
            };
            //
            while (PageLoaded.Task.Status != TaskStatus.RanToCompletion)
            {
                await Task.Delay(10);//interval of 10 ms worked good for me
                TimeElapsed++;
                if (TimeElapsed >= TimeOut * 100) PageLoaded.TrySetResult(true);
            }
         
        }
        private void nav() {
             sites = File.ReadLines(@"C:\Users\Chris\Desktop\sb\sites.txt").ToArray();
            var proxies = File.ReadLines(@"C:\Users\Chris\Desktop\sb\proxies.txt").ToArray();
           

            var site = sites.ElementAt(0);
            navigeUrl(site);

            //foreach (var i in sites)
            //{
               
            //}

        }

        private async void navigeUrl(string url)
        {

            webBrowser1.Navigate(url);
            await PageLoad(10);
        }
        static void Run()
        {
            var sites = File.ReadLines(@"C:\Users\Chris\Desktop\sb\sites.txt");
            var proxies = File.ReadLines(@"C:\Users\Chris\Desktop\sb\proxies.txt");
            var res = (from i in proxies select i).ToArray();
            var counter = 0;
            var totalData = 0;
            var site = sites.ElementAt(0);
            for (var z = 0; z < 500; z++)
            {

                foreach (var i in sites)
                {
                    try
                    {
                        using (WebClient Client = new WebClient())
                        {
                            var index = counter++ % (res.Length - 1);
                            Client.Proxy = new WebProxy(res[index]);
                            //  var ret = Client.DownloadData(i);
                            var ret = Client.DownloadString(i);

                            // var ret = Client.DownloadData(site);
                            totalData += ret.Length;
                            Console.WriteLine($"{(totalData / 1024f) / 1024f} ----- {(ret.Length / 1024f) / 1024f}");
                        }
                    }
                    catch
                    {

                    }



                }

            }
        }
        static void RunMultiThread()
        {
            var sites = File.ReadLines(@"C:\Users\Chris\Desktop\sb\sites.txt");
            var proxies = File.ReadLines(@"C:\Users\Chris\Desktop\sb\proxies.txt");
            var res = (from i in proxies select i).ToArray();
            var counter = 0;
            var totalData = 0;
            var site = sites.ElementAt(0);
            for (var z = 0; z < 64; z++)
            {
                Thread t = new Thread(() =>
                {
                    foreach (var i in sites)
                    {
                        try
                        {
                            using (WebClient Client = new WebClient())
                            {
                                // var index = counter++ % (res.Length - 1);
                                //   Client.Proxy = new WebProxy(res[index]);
                                var ret = Client.DownloadData(i);

                                // var ret = Client.DownloadData(site);
                                totalData += ret.Length;
                                Console.WriteLine($"{(totalData / 1024f) / 1024f} ----- {(ret.Length / 1024f) / 1024f}");
                            }
                        }
                        catch
                        {

                        }



                    }


                });


            }
        }
    }
}


