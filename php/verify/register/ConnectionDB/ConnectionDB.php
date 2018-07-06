<?php

namespace Mailer;

class ConnectionDB
{
    //настройки подключения к базе данных
    private $dbuser = 'root';
    private $dbpass = '';
    private $host = 'localhost';
    private $dbname = 'register';
    private $db;

    //метод подключения к базе данных
    public function Connection()
    {
        try {
            $this->db = new \PDO('mysql:host=' . $this->host . ';dbname=' . $this->dbname . ';charset=utf8', $this->dbuser, $this->dbpass); // подключение к б/д
            // настройка режима работы с ошибками - выкидывать исключения
            $this->db->setAttribute(\PDO::ATTR_ERRMODE, \PDO::ERRMODE_EXCEPTION);
            $sql = 'use ' . $this->dbname;
            $this->db->exec($sql);
        } catch (\PDOException $ex) {
            echo "<p style='color:red'>";
            echo $ex->getMessage();
            echo "</p>";
        }
    }

    //проверка произошло ли подключения к базе данных
    public function CheckBDNotNull()
    {
        return $this->db !== null ? true : false;
    }

    //проверяет наличие логина в базе данных
    public function CheckLoginInBD($login)
    {
        $sql = "select * from user where login=:login";
        $stmt = $this->db->prepare($sql);
        $stmt->bindParam("login", $login, \PDO::PARAM_STR);
        $stmt->execute();
        return $stmt->fetch();
    }

    //проверяет наличие email в базе данных
    public function CheckEmailInBD($email)
    {
        $sql = "select * from user where email=:email";
        $stmt = $this->db->prepare($sql);
        $stmt->bindParam("email", $email, \PDO::PARAM_STR);
        $stmt->execute();
        return $stmt->fetch();
    }

    public function AddUserToDataBase($user)
    {
        $hash = password_hash($user->getPassword(), PASSWORD_DEFAULT);
        $activation = md5(rand(-10000, 100000));
        $sql = "INSERT INTO user (login, email, password, activation,status) values(:login,:email,:password,:activation,'inactive')";
        $stm = $this->db->prepare($sql);
        $stm->execute(array(':login' => $user->getLogin(), ':email' => $user->getEmail(), ':password' => $hash, ':activation' => $activation));
        return $activation;
    }

    public function SetActiveStatus($codeActivation)
    {
        $sql = "select * from user where activation=:activation";
        $stm = $this->db->prepare($sql);
        $date = $stm->execute(array(':activation' => $codeActivation));
        $row = $stm->fetch(\PDO::FETCH_ASSOC);
        if ($date != false) {
            $id = (int)$row['id'];
            $sql = "UPDATE user SET status = 'active' where id like " . $id;
            $stm = $this->db->prepare($sql);
            $date2 = $stm->execute();
            return true;
        }
        return false;
    }

    //отключение от базы даннх
    public function Disconnect()
    {
        $this->db = null; // отключение от б/д
    }

    //проверка наличия пользователя в бд
    public function CheckUser($login, $password)
    {
        $sql = "select * from user where login=:login and password=:password";
        $stm = $this->db->prepare($sql);
        return $stm->execute(array(':login' => $login, ':password' => password_hash($password, PASSWORD_DEFAULT)));
    }
}