#include <fstream>
#include <iostream>
//colaborate test

void createCheckerboard(unsigned char* image, int width, int height, int rectsCount)
{
	int deltaW = width / (2 * rectsCount);
	int deltaH = height / (2 * rectsCount);

	for (int j = 0; j < 2 * rectsCount; ++j)
	{
		for (int i = 0; i < 2 * rectsCount; ++i)
		{
			int x0 = i*deltaW;
			int y0 = j*deltaH;
			unsigned char color = ((i+j%2) % 2) * 255;
			for (int y = y0; y < y0 + deltaH; ++y)
			{
				for (int x = x0; x < x0 + deltaW; ++x)
				{
					image[y*width + x] = color;
				}
			}
		}
	}
}

void writeToPPM(std::ofstream& os, unsigned char* image, int width, int height)
{
	char res[5];
	os << "P3\n"; //format hint (3 channels)
	os << width << " "; //width
	os << height << "\n"; //height
	os << 255 << "\n"; //max value
	int k = 0;
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			os << (int)image[k] << "\t" << (int)image[k] << "\t" << (int)image[k] << "\t\t";
			++k;
		}
		os << "\n";
	}

}



int main()
{
	std::ofstream outputFile;
	outputFile.open("output.ppm");
	int width = 320;
	int height = 240;
	int rectsCount = 20;
	
	unsigned char* image = new unsigned char[width*height];
	createCheckerboard(image, width, height, rectsCount);
	writeToPPM(outputFile, image, width, height);

	return 0;
}
