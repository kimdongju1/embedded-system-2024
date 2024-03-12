# embedded-system-2024
IoT 개발자 임베디드시스템 학습 리포지토리

## 1일차 

- 라즈베리파이 소프트웨어 설치
	- sd 카드 usb에 꽂기 
 	- sdcard formatter 로 sd 카드 포맷 다운로드
	- Quick format
	- usb sd card 연결후 라즈베리파이- 장치 선택 -라즈베리파이 4 선택, 운영체제 Pi-OS(64bit)
	- 저장소 선택 , 설정 편집 , name(raspi 변경) , 사용자이름: pi 비밀번호 raspi/ 무선LAN설정 SSID: iptime2G_2/iot212345
	- 무선랜국가, 시간대, 키보드레아웃 kr로 설정/ SSH사용 체크 

- -들어갈때
	- id:pi
	- password:raspi

- -나갈때 sudo shutdown now

- 	1. sudo apt update
- 	2. sudo apt upgrade -y
- 	3. clear
- 	4. 환경설정
	- 편집기: 코드 작업할 때 사용하는 프로그램(nano) 한글
- 	5. 기본명령어(C)
- * 기존 PC같이 사용하면 안된다.
- - 순서에 맞추어서 사용(동작중에 다른 명령어 처리 안됨)

- - 기본명령어
	- 현재 내위치 확인 : pwd
	- 현재 목록 확인 : ls (파란색 글씨는 폴더, 하얀색 글씨 파일)
	- 디렉토리 생성 : mkdir 디렉토리이름
	- 디렉토리 삭제 : rm -fr 디렉토리 이름
	- 숨겨진 파일까지 확인 : ls -a
	- 화면 지우기 : clear
	- 상세하게 보여주기 : ls -1
	- 디렉토리 들어가기 : cd 디렉토리이름
	- 상위 디렉토리로 빠져나가기 : cd ..
	- 환경 관련 파일, 디렉토리 : ls /etc
	- 관리자 권한 : sudo
	- 빠져나오기 : ctrl + x