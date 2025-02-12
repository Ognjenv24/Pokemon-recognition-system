<a id="readme-top"></a>

# Object Recognition in Images

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![project_license][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

---

## About The Project

The project focuses on developing a software solution for recognizing, counting, and labeling objects in digital images based on color. The program uses color segmentation, morphological operations, and contour detection to identify 10 different Pokémon characters.

### Built With

- C++
- OpenCV
- SystemC
- Vitis HLS
- Vivado

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## Getting Started

### Prerequisites

- Installation of OpenCV library
- C++ compiler

### Installation

1. Clone the repository
   ```sh
   git clone https://github.com/github_username/repo_name.git
   ```
2. Install dependencies
   ```sh
   sudo apt-get install libopencv-dev
   ```
3. Run the program
   ```sh
   ./program input.jpg
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## Usage

The system recognizes objects based on color and marks them with rectangles along with textual descriptions. It runs from the command line with given images as input parameters.

**Example usage:**
```sh
./program image.jpg
```

**Output:**
- Display of the image with marked objects
- Standard output with the number of recognized objects

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## Profiling

Performance analysis was conducted using the Valgrind Callgrind tool. Optimizations include improved segmentation and manual memory management to enhance performance.

**Key findings:**
- `cv::inRange` - 26.99% execution time
- `cv::morphologyEx` - 19.90%
- `cv::findContours` - 8.94%

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## Virtual Platform

The system is simulated using SystemC and TLM modeling, with components:
- **CPU** - Loads images and manages processing
- **Interconnect** - Routes data between CPU, BRAM, and IP modules
- **BRAM** - Stores images
- **IP module** - Image processing

![Virtual platform block diagram](images/virtual-platform.png)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## Bit Analysis

The number of bits used for various variables in the code was analyzed to optimize memory efficiency. Key changes include:
- Using `short` instead of `int` for image dimensions
- More efficient storage of colors in `unsigned char` format

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## HLS Synthesis

Vitis HLS was used to evaluate the IP block's latency. Results:
- Latency: **8.5 ns**
- IP block frequency: **117.65 MHz**
- System throughput: **10 images per second**

![Processing time](images/processing-time.png)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## Conclusion

The project demonstrates efficient object recognition in images based on color using optimized algorithms and a virtual platform. Future developments may include expanding recognition to additional objects and improving resistance to lighting changes.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## References

1. [OpenCV - Open Computer Vision Library](https://opencv.org/)
2. [SystemC](https://systemc.org/)
3. [Vitis HLS](https://xilinx.github.io/Vitis-Tutorials/)
4. [Virtual Platform Documentation](https://www.elektronika.ftn.uns.ac.rs/)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
[contributors-shield]: https://img.shields.io/github/contributors/github_username/repo_name.svg?style=for-the-badge
[contributors-url]: https://github.com/github_username/repo_name/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/github_username/repo_name.svg?style=for-the-badge
[forks-url]: https://github.com/github_username/repo_name/network/members
[stars-shield]: https://img.shields.io/github/stars/github_username/repo_name.svg?style=for-the-badge
[stars-url]: https://github.com/github_username/repo_name/stargazers
[issues-shield]: https://img.shields.io/github/issues/github_username/repo_name.svg?style=for-the-badge
[issues-url]: https://github.com/github_username/repo_name/issues
[license-shield]: https://img.shields.io/github/license/github_username/repo_name.svg?style=for-the-badge
[license-url]: https://github.com/github_username/repo_name/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/linkedin_username

