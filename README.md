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
### ``listener.cpp`` 코드 설명

```cpp
  thread t1(glutMainLoop);
  ros::spin();
  t1.join();
```

- ``glutMainLoop()`` 와 ``spin()`` 모두 반복을 요하는 메소드 이다. 
  - ``ros::spin()`` : 프로그램이 종료 될때까지 반복해서 큐에 요청된 콜백함수를 처리
  - ``glutMainLoop()`` : ``OpenGL`` 이벤트 처리 루프
- ``glutMainLoop()`` 로 스레드로 실행시켜 아래의 코드 ``ros::spin()`` 가 실행 될수 있도록 한다.

## ``OpenGL CMake``

- ``opengl_with_cmake`` 폴더를 통해 ``OpenGL``기본 예제를 ``CMake``로 실행시킬수 있다.

```bash
cmake CMakeLists.txt
make
cd bin
./run_file
```
