cd /root/mesos-0.28.1/build

make

cp ./src/.libs/libmesos-0.28.1.so /root/mesos-slave-with-hook/so/
cp ./src/.libs/libpostlaunchdockerhook-0.28.1.so /root/mesos-slave-with-hook/so/
cp ./src/libmesos.la /root/mesos-slave-with-hook/so/
cp ./src/libpostlaunchdockerhook.la /root/mesos-slave-with-hook/so/

cp ./src/.libs/mesos-containerizer /root/mesos-slave-with-hook/libexec/
cp ./src/.libs/mesos-docker-executor /root/mesos-slave-with-hook/libexec/
cp ./src/.libs/mesos-executor /root/mesos-slave-with-hook/libexec/
cp ./src/.libs/mesos-fetcher /root/mesos-slave-with-hook/libexec/
cp ./src/.libs/mesos-health-check /root/mesos-slave-with-hook/libexec/
cp ./src/.libs/mesos-logrotate-logger /root/mesos-slave-with-hook/libexec/
cp ./src/.libs/mesos-usage /root/mesos-slave-with-hook/libexec/

cd /root
