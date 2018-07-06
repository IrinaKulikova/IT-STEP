<?php
/**
 * Created by PhpStorm.
 * User: User
 * Date: 022 22.05.18
 * Time: 14:58
 */

namespace Mailer;

class UserDB
{
    private $login;
    private $email;
    private $password;

    public function  __construct($login, $email, $password)
    {
        $this->login=$login;
        $this->password=$password;
        $this->email=$email;
    }

    public  function getLogin(){
        return $this->login;
    }

    public  function getEmail(){
        return $this->email;
    }

    public  function getPassword(){
        return $this->password;
    }
}