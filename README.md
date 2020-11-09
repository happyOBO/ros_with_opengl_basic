# ros_with_opengl_basic

## 설명

- ROS 와 함께 OpenGL를 함께 이용하는 기본 프로그램
- 퍼블리셔에서 메시지를 전송할 경우 서브스크라이버에 의해 ``OpenGL``을 통해 전송되는 윈도우 이미지 색깔이 빨간색에서 노란색으로 변함

## 실행방법

- 깃 클론 후 빌드

```bash
cd catkin_ws/src
git clone https://github.com/happyOBO/ros_with_opengl_basic.git
catkin build
source ./devel/setup.bash
```

- 한 터미널에는 퍼블리셔, 다른 터미널에는 서브스크라이버 실행

```bash
rosrun ros_with_opengl_basic talker
```

```bash
rosrun ros_with_opengl_basic listener
```


## ``OpenGL CMake``

- ``opengl_with_cmake`` 폴더를 통해 ``OpenGL``기본 예제를 ``CMake``로 실행시킬수 있다.

```bash
cmake CMakeLists.txt
make
cd bin
./run_file
```