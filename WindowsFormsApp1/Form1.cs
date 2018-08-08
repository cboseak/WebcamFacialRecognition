using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Emgu.CV;
using Emgu.CV.Face;
using Emgu.CV.Structure;
using FacePlusPlus;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        VideoCapture _capture;
        private Mat _frame;
        Image<Gray, byte> currFrame;
        static string xmlDir = $@"C:\Users\Chris\Desktop\test3\haarcascade_frontalface_alt_tree.xml";
       // var sf = new SharpFace.LandmarkDetectorWrap(@"C:\Users\Chris\Desktop\test3\models");
        CascadeClassifier Classifier = new CascadeClassifier(xmlDir);
        static EigenFaceRecognizer faceRecognizerEigen = new EigenFaceRecognizer(80, double.PositiveInfinity);
        static LBPHFaceRecognizer faceRecognizerLBPH = new LBPHFaceRecognizer(1,5, 8, 8, 40);
        static FisherFaceRecognizer faceRecognizerFisher = new FisherFaceRecognizer(0, 5000);

        private void ProcessFrame(object sender, EventArgs e)
        {
            if (_capture != null && _capture.Ptr != IntPtr.Zero)
            {
                _capture.Retrieve(_frame, 0);
                var f =new Image<Gray, byte>(_frame.Bitmap).Mat;
                //   sf.Draw(f);
                 pictureBox1.Image = MarkFace(_frame.Bitmap);
            }
        }
        string GetPerson(int id)
        {
            var ret = "";
            switch (id)
            {
                case 1:
                    ret = "Chris";
                    break;
                case 2:
                    ret = "Destinee";
                    break;
                case 3:
                    ret = "Liam";
                    break;
                case 4 :
                    ret = "Logan";
                    break;
                default:
                    ret = "";
                    break;
            }
            return ret;
        }
        Bitmap MarkFace(Bitmap inFile)
        {
            currFrame = new Image<Gray, byte>(inFile);
            using (Graphics gr = Graphics.FromImage(inFile))
            {
                using (Pen thick_pen = new Pen(Color.Red, 2))
                {
                    var faces = Classifier.DetectMultiScale(currFrame.Mat);
                    foreach (var rect in faces)
                    {
                        var match = CheckForMatch(currFrame.GetSubRect(rect));
                        currFrame.Draw(rect,new Gray(),5);
                        //gr.SmoothingMode = SmoothingMode.AntiAlias;
                        ////  gr.FillEllipse(Brushes.LightGreen, rect);

                        //      gr.DrawRectangle(thick_pen, rect);

                        //gr.DrawString(GetPerson(match), new Font("Tahoma", 18), Brushes.Red, rect);
                    }
                }
            }

            //    GC.Collect();
            return inFile;
        }
        public Form1()
        {
            InitializeComponent();
            // saveAllCrops(ProcessDirectory(@"C:\Users\Chris\Desktop\test3\raw pics"));
               loadPics();
 
            _capture = new VideoCapture(0);


            _capture.ImageGrabbed += ProcessFrame;
            _frame = new Mat();
            if (_capture != null)
            {
                try
                {
                    _capture.Start();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }

        }
        void loadPics()
        {
            var me = getAllImages(ProcessDirectory(@"C:\Users\Chris\Desktop\test3\crops\chris"));
            var des = getAllImages(ProcessDirectory(@"C:\Users\Chris\Desktop\test3\crops\destinee"));
            var liam = getAllImages(ProcessDirectory(@"C:\Users\Chris\Desktop\test3\crops\liam"));
            var logan = getAllImages(ProcessDirectory(@"C:\Users\Chris\Desktop\test3\crops\logan"));

            var trainingData = new List<Image<Gray, Byte>>();
            var trainingLabels = new List<int>();

            AddToTrainingData(ref trainingData, ref trainingLabels, me, 1);
            AddToTrainingData(ref trainingData, ref trainingLabels, des, 2);
            AddToTrainingData(ref trainingData, ref trainingLabels, liam, 3);
            AddToTrainingData(ref trainingData, ref trainingLabels, logan, 4);


           // faceRecognizerEigen.Train<Gray, Byte>(trainingData.ToArray(), trainingLabels.ToArray());
            faceRecognizerLBPH.Train<Gray, Byte>(trainingData.ToArray(), trainingLabels.ToArray());
          //  faceRecognizerFisher.Train<Gray, Byte>(trainingData.ToArray(), trainingLabels.ToArray());


        }
        int CheckForMatch(Image<Gray, Byte> i)
        {
            i = new Image<Gray, Byte>(CropFace(i.Bitmap, 300));
         //   var EigenRes = faceRecognizerEigen.Predict(i);
            var LBPHRes = faceRecognizerLBPH.Predict(i);
           // var FisherRes = faceRecognizerFisher.Predict(i);

            return LBPHRes.Label;


        }
        private void button1_Click(object sender, EventArgs e)
        {
            _frame.Bitmap.Save($@"C:\Users\Chris\Desktop\test3\{_frame.Bitmap.GetHashCode()}.bmp");
        }
        static void AddToTrainingData(ref List<Image<Gray, Byte>> data, ref List<int> labels, List<Image<Gray, Byte>> inImgs, int label)
        {
            foreach (var e in inImgs)
            {
                data.Add(e);
                labels.Add(label);
            }

        }
        static string[] ProcessDirectory(string targetDirectory)
        {
            // Process the list of files found in the directory.
            return Directory.GetFiles(targetDirectory);

        }

        List<Image<Gray, Byte>> getAllImages(string[] paths, int minSize = 300)
        {
            var count = 0;

            var Rand = new Random();
            var ret = new List<Image<Gray, Byte>>();
            foreach (var p in paths)
            {

                var img = loadGrayImage(p);//.Resize(minSize, minSize, Emgu.CV.CvEnum.Inter.Cubic);


                //var faces = Classifier.DetectMultiScale(img.Mat);
                //if (!faces.Any()) continue;

                //var rect = faces.First();
                //var crop = img.GetSubRect(rect);

                ret.Add(new Image<Gray, Byte>(CropFace(img.Bitmap, minSize)));





            }
            return ret;
        }
        void saveAllCrops(string[] paths, int minSize = 300)
        {
            var xmls = ProcessDirectory(@"C:\Users\Chris\Desktop\tutorial-haartraining-master\data\haarcascades");
            var count = 0;
            foreach (var x in xmls)
            {
                count++;
                Classifier = new CascadeClassifier(x);
                foreach (var p in paths)
                {

                    var img = loadGrayImage(p);//.Resize(minSize, minSize, Emgu.CV.CvEnum.Inter.Cubic);


                    var faces = Classifier.DetectMultiScale(img.Mat);
                    foreach (var f in faces)
                    {
                        var crop = img.GetSubRect(f);
                        crop.Bitmap.Save($@"C:\Users\Chris\Desktop\test3\crops\xmlResults\{count}\{crop.GetHashCode()}.bmp");
                    }

                }

            }
        }
        static Bitmap CropFace(Bitmap bmp, int size)
        {
            var ret = new Bitmap(bmp, new Size(size, size));
            //   ret.Save($@"C:\Users\chris.boseak\Desktop\sdfsdf\training\labelled\crops\{bmp.GetHashCode()}.bmp");
            return ret;
        }
        static Bitmap CropFace(Image<Gray, Byte> img, int size)
        {
            var bt = img.ToBitmap();
            // bt.Save($@"C:\Users\Chris\Desktop\test3\crops\{bt.GetHashCode()}.bmp");
            return CropFace(bt, size);
        }
        static Bitmap MarkFace(Bitmap inFile, Rectangle[] rects)
        {
            foreach (var rect in rects)
            {
                using (Graphics gr = Graphics.FromImage(inFile))
                {
                    gr.SmoothingMode = SmoothingMode.AntiAlias;
                    //  gr.FillEllipse(Brushes.LightGreen, rect);
                    using (Pen thick_pen = new Pen(Color.Red, 5))
                    {
                        gr.DrawRectangle(thick_pen, rect);
                    }
                }
            }


            return inFile;
        }

        static Image<Gray, Byte> loadGrayImage(string path)
        {
            var img1 = new Image<Gray, Byte>(path);
            return img1;
        }
        static Image<Bgr, Byte> loadBgrImage(string path)
        {
            var img1 = new Image<Bgr, Byte>(path);
            return img1;
        }
    }
}
